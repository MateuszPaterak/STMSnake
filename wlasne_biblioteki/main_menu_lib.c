//#include "snakelib.h"
#include "include.h"

//#include "main_menu_lib.h"

void DrawGameMainMenu()
    {
    PCD8544_Clear();
    PCD8544_GotoXY(1,1);
    PCD8544_Puts("Start gry",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,9);
    PCD8544_Puts("Poziom trundosci",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,17);
    PCD8544_Puts("Najwy¿sze wyniki",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,25);
    PCD8544_Puts("Resetuj wyniki",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);
    }

void DrawMenuSelectionFrame7x5(unsigned char top_y, PCD8544_Pixel_t color)
    {
    PCD8544_DrawRectangle(0,top_y,83,top_y+8,color);
    }
