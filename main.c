#include "include.h"
#include "bitmap.h"
#include "stm32f4xx_rng.h"

#include "button.h"
#include "snake_game.h"
#include "snake_engine.h"
#include "TimerConfig.h"
#include "main_menu_lib.h"

//#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_fatfs.h"

int main(void)
{
    SystemInit();

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

    ConfTim3(350); //init with 0,5s game period


    PCD8544_Init(0x38); 				//Initialize LCD with 0x38 software contrast


////////////////////////////////////////////
    DrawBitMap(SnakeBitMap3310Vertical);
    PCD8544_Refresh();
    PCD8544_Delay(10000000);
    PCD8544_Clear();

    //StartSnakeGame();
    MainMenu();



    while (1)
	{

	}
}
