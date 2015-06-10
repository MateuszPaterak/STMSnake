#include "include.h"
#include "bitmap.h"
#include "stm32f4xx_rng.h"
#include "button.h"
#include "snake_game.h"
#include "snake_engine.h"
#include "TimerConfig.h"
#include "main_menu_lib.h"

#include "delay.h"
#include "fpu.h"
#include "spi_sd.h"
#include "ff.h"


int main(void)
{
    SystemInit();

    ////////////////// SPI 2 SD
    fpu_enable();
    delay_init( 168 );
    SPI_SD_Init();
    //////////////////

    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);//rng
    RNG_Cmd(ENABLE); //switch on

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //button

    InitEXTIButtonPA0();//akcept
    InitEXTIButtonPA1();//up
    InitEXTIButtonPA2();//right
    InitEXTIButtonPA3();//down
    InitEXTIButtonPA4();//left

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //timer
    ConfTim2();
    //SystemCoreClockUpdate();
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //timer

    ConfTim3(350); //init with _ s game period
    SetSnakeSpeed(3);

    PCD8544_Init(0x38); 				//Initialize LCD with 0x38 software contrast
////////////////////////////////////////////
    //DrawBitMap(SnakeBitMap3310Vertical);
    DrawBitMap(Snake2);

    PCD8544_Refresh();
    WaitForAkceptButton();
    PCD8544_Clear();


    MainMenu();

    while (1)
	{

	}
}

/* FatFs module application interface                           */
/*
FRESULT f_mount (BYTE, FATFS*);				// Mount/Unmount a logical drive
FRESULT f_open (FIL*, const TCHAR*, BYTE);		// Open or create a file
FRESULT f_read (FIL*, void*, UINT, UINT*);		// Read data from a file
FRESULT f_lseek (FIL*, DWORD);				// Move file pointer of a file object
FRESULT f_close (FIL*);					// Close an open file object
FRESULT f_opendir (DIR*, const TCHAR*);			// Open an existing directory
FRESULT f_readdir (DIR*, FILINFO*);			// Read a directory item
FRESULT f_stat (const TCHAR*, FILINFO*);		// Get file status


FRESULT f_write (FIL*, const void*, UINT, UINT*);	// Write data to a file
FRESULT f_getfree (const TCHAR*, DWORD*, FATFS**);	// Get number of free clusters on the drive
FRESULT f_truncate (FIL*);				// Truncate file
FRESULT f_sync (FIL*);					// Flush cached data of a writing file
FRESULT f_unlink (const TCHAR*);			// Delete an existing file or directory
FRESULT	f_mkdir (const TCHAR*);				// Create a new directory
FRESULT f_chmod (const TCHAR*, BYTE, BYTE);		// Change attriburte of the file/dir
FRESULT f_utime (const TCHAR*, const FILINFO*);		// Change timestamp of the file/dir
FRESULT f_rename (const TCHAR*, const TCHAR*);		// Rename/Move a file or directory
*/
