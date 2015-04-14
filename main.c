#include "include.h"
//#include "logo.h"
#include "bitmap.h"
#include "main_menu_lib.h"

int main(void)
{
    //180MHz
    SystemInit();

    //Initialize LCD with 0x38 software contrast
    PCD8544_Init(0x38);

    DrawBitMapVertical(SnakeBitMap3310Vertical);
    PCD8544_Refresh();
    PCD8544_Delay(20000000);

    DrawGameMainMenu();
    DrawMenuSelectionFrame7x5(0,PCD8544_Pixel_Set);
    PCD8544_Refresh();

    while (1)
    {
	/*
	 * Demo
	 */
	DrawMenuSelectionFrame7x5(0,PCD8544_Pixel_Set);
	PCD8544_Refresh();
	PCD8544_Delay(5000000);

	DrawMenuSelectionFrame7x5(0,PCD8544_Pixel_Clear);
	DrawMenuSelectionFrame7x5(8,PCD8544_Pixel_Set);
	PCD8544_Refresh();
	PCD8544_Delay(5000000);

	DrawMenuSelectionFrame7x5(8,PCD8544_Pixel_Clear);
	DrawMenuSelectionFrame7x5(16,PCD8544_Pixel_Set);
	PCD8544_Refresh();
	PCD8544_Delay(5000000);

	DrawMenuSelectionFrame7x5(16,PCD8544_Pixel_Clear);
	DrawMenuSelectionFrame7x5(24,PCD8544_Pixel_Set);
	PCD8544_Refresh();
	PCD8544_Delay(5000000);

	DrawMenuSelectionFrame7x5(24,PCD8544_Pixel_Clear);
    }
}
