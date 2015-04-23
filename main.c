#include "include.h"
#include "bitmap.h"
#include "stm32f4xx_rng.h"


int main(void)
{
    char *tab = calloc(20,sizeof(char));
    tab[10]=6;
    tab[11]=7;
    tab[12]=8;
    tab[13]=9;
    tab[14]=10;

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
	int i=0;
	for(;i<20;i++)
	    {
	    DrawFilledBoxInGrid(i,tab[i],PCD8544_Pixel_Set);
	    PCD8544_Refresh();
	    PCD8544_Delay(1000000);
	    }
	//DemoRandomPikselBoxGenerator();
	//PCD8544_Refresh();
	//PCD8544_Delay(1000000);


	}
}
