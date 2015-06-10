/*
 * main.c
 *      Author: Grzegorz H.
 */
#include "lib_cm4/stm32f4xx.h"
#include "lib_cm4/system_stm32f4xx.h"
#include "delay/delay.h"
#include "lib_cm4/fpu.h"
#include "FatFs_SD/spi_sd.h"
#include "FatFs_SD/ff.h"

FATFS fatfs;
FIL plik;
FRESULT fresult;
UINT zapisanych_bajtow = 0;
UINT zapianie_bajtow = 0;
char * buffor = "123456789abcdef\r\n";
uint16_t i;

int main( void )
{
    SystemInit();
    fpu_enable();
    delay_init( 168 );
    SPI_SD_Init();

    fresult = f_mount( 0, &fatfs );
    fresult = f_open( &plik, "plik.txt", FA_OPEN_ALWAYS | FA_WRITE );
    if( fresult == FR_OK )
    {
    	for( i = 0; i < 1000; i++ )
            fresult = f_write( &plik, ( const void * ) buffor, 17, &zapisanych_bajtow );
    }

    fresult = f_close( &plik );

    for(;;)
    {

    }

	return 0;
}
