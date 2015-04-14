#include "include.h"
//#include "logo.h"
#include "bitmap.h"
#include "main_menu_lib.h"

#include "tm_stm32f4_rng.h"

int main(void)
{
    //180MHz
    SystemInit();

    TM_RNG_Init(); //RNG start

    //Initialize LCD with 0x38 software contrast
    PCD8544_Init(0x38);

    DrawBitMapVertical(SnakeBitMap3310Vertical);
    PCD8544_Refresh();
    PCD8544_Delay(20000000);


    uint32_t x;

    while (1)
	{
	PCD8544_Clear();
	DemoRandomPikselBoxGenerator();
	PCD8544_Refresh();
	PCD8544_Delay(10000000);


    }
}
