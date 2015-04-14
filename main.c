#include "include.h"
#include "bitmap.h"

int main(void)
{
    //180MHz
    SystemInit();

    TM_RNG_Init(); //RNG start

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
