
#include "tm_stm32f4_pcd8544.h"
//#include "include.h"

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
void DrawMenuSelectionFrameSet7x5(unsigned char top_x, PCD8544_Pixel_t color);

