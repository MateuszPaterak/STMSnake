#include "include.h"
#include "bitmap.h"
#include "stm32f4xx_rng.h"

#include "button.h"
#include "snake_game.h"


int main(void)
{
    SystemInit();

    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);
    RNG_Cmd(ENABLE); //switch on

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //button
    InitEXTIButtonPA0();//left
    InitEXTIButtonPA1();//up
    InitEXTIButtonPA2();//right
    InitEXTIButtonPA3();//down
    InitEXTIButtonPA4();//akcept
    PCD8544_Init(0x38); 				//Initialize LCD with 0x38 software contrast


////////////////////////////////////////////
    DrawBitMap(SnakeBitMap3310Vertical);
    PCD8544_Refresh();
    PCD8544_Delay(10000000);
    PCD8544_Clear();

    StartSnakeGame();

    while (1)
	{
	//DemoRandomPikselBoxGenerator();
	//PCD8544_Refresh();
	//PCD8544_Delay(1000000);


	}
}
