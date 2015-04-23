#include "include.h"
#include "bitmap.h"
#include "stm32f4xx_rng.h"

int main(void)
{
    //180MHz
    SystemInit();


    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);
    RNG_Cmd(ENABLE); //switch on
    /*
    RNG_ClearFlag(RNG_FLAG_CECS);
    while (RNG_GetFlagStatus(RNG_FLAG_DRDY == RESET)) {   }
    */

    //Initialize LCD with 0x38 software contrast
    PCD8544_Init(0x38);

    DrawBitMap(SnakeBitMap3310Vertical);
    PCD8544_Refresh();
    PCD8544_Delay(10000000);
    PCD8544_Clear();

    while (1)
	{

	DemoRandomPikselBoxGenerator();
	PCD8544_Refresh();
	PCD8544_Delay(1000000);


	}
}
