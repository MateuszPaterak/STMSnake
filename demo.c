#include "snakelib.h"
#include "tm_stm32f4_pcd8544.h"
//#include "tm_stm32f4_rng.h"
#include "main_menu_lib.h"
#include "demo.h"

#include "stm32f4xx_rng.h"

/*
void DemoRandomPikselBoxGenerator(void)
    {
    uint32_t x,y;

    x = TM_RNG_Get() % (84/BOXDIM);
    y = TM_RNG_Get() % (48/BOXDIM);

   // DrawEmptyBoxInGrid(x,y);
    DrawFilledBoxInGrid(x,y,PCD8544_Pixel_Set);
    }
*/

/*
 * STMLibRNG
 */
void DemoRandomPikselBoxGenerator(void)
    {
    uint32_t x,y;
    while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET)    {}
    x = RNG_GetRandomNumber() % (84/BOXDIM);
    while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET)    {}
    y = RNG_GetRandomNumber() % (48/BOXDIM);

   // DrawEmptyBoxInGrid(x,y);
    DrawFilledBoxInGrid(x,y,PCD8544_Pixel_Set);
    PCD8544_Refresh();
    }

void DemoDrawMenu(void)
    {
	DrawGameMainMenu();
	DrawMenuSelectionFrame7x5(0,PCD8544_Pixel_Set);
	PCD8544_Refresh();

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
