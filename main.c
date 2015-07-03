#include "snakelib.h"
#include "bitmap.h"
#include "stm32f4xx_rng.h"
#include "button.h"
#include "snake_game.h"
#include "snake_engine.h"
#include "TimerConfig.h"
#include "main_menu_lib.h"
#include "fpu.h"
#include "delay.h"
#include "spi_sd.h"


int main(void)
{
    SystemInit();

    ////////////////// SPI2 - SD
    fpu_enable();
    delay_init( 168 );
    SPI_SD_Init();
    //////////////////

    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);	  //rng
    RNG_Cmd(ENABLE); //switch on

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //button

    InitEXTIButtonPA0();//accept
    InitEXTIButtonPA1();//up
    InitEXTIButtonPA2();//right
    InitEXTIButtonPA3();//down
    InitEXTIButtonPA4();//left

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //timer
    ConfTim2();

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //timer

    ConfTim3(350); //init with start_value game period
    SetSnakeSpeed(3);

    PCD8544_Init(0x38); 				//Initialize LCD with 0x38 software contrast
////////////////////////////////////////////

    DrawBitMap(SnakeBitMap);

    PCD8544_Refresh();
    WaitForAcceptButton();
    PCD8544_Clear();

    MainMenu();

    while (1)
	{

	}
}
