
#include "tm_stm32f4_pcd8544.h"

/*
 *  Main Menu Snake's game
 */
void DrawGameMainMenu();

/*
 *  Draw mini frame around selected  menu's position
 *  PCD8544_Pixel_t color:
     - PCD8544_Pixel_Clear
     - PCD8544_Pixel_Set
 */
void DrawMenuSelectionFrame7x5(unsigned char top_y, PCD8544_Pixel_t color);

