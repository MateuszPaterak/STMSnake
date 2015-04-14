#include "snakelib.h"
#include "include.h"

//?do poprawki wype³nianie boxami - wspó³rzêdne liczone s¹ od 0, dlatego druga para x,y musi byæ -1
// nie testowane wszyskie dok³adnie


void DrawFilledBox(unsigned char x, unsigned char y, PCD8544_Pixel_t color)
    {
    PCD8544_DrawFilledRectangle(x, y, x+BOXDIMENSION-1, y+BOXDIMENSION-1, color);
    }


void DrawEmptyBox(unsigned char x, unsigned char y)
    {
    PCD8544_DrawFilledRectangle(x, y, x+BOXDIM-1, y+BOXDIM-1, PCD8544_Pixel_Set);
    PCD8544_DrawFilledRectangle(x+1, y+1, x-2+BOXDIM, y-2+BOXDIM, PCD8544_Pixel_Clear);
    }

//Grid - siatka
void DrawFilledBoxInGrid(unsigned char xg, unsigned char yg, PCD8544_Pixel_t color) //ok
    {
    PCD8544_DrawFilledRectangle(xg*BOXDIM, yg*BOXDIM, xg*BOXDIM+BOXDIM-1, yg*BOXDIM+BOXDIM-1, color);
    }

void DrawEmptyBoxInGrid(unsigned char xg, unsigned char yg)//ok
    {
    PCD8544_DrawFilledRectangle(xg*BOXDIM, yg*BOXDIM, xg*BOXDIM+BOXDIM-1, yg*BOXDIM+BOXDIM-1, PCD8544_Pixel_Set);
    PCD8544_DrawFilledRectangle(xg*BOXDIM+1, yg*BOXDIM+1, xg*BOXDIM+BOXDIM -2 , yg*BOXDIM+BOXDIM -2 , PCD8544_Pixel_Clear);
    }

void DrawBitMap(unsigned char *bitmap)
    {
    int i,j;

    for(i=0; i<6; i++)
	for(j=0; j<84; j++)
	{
	    _HelpDrawBitMap(i,j,bitmap);
	    bitmap++;
	}
    }

//Flipped - przerzucony
void DrawBitMapVerticalFlipped(unsigned char *bitmap)
    {
    int i,j;

    for(i=0; i<6; i++)
	for(j=83; j>=0; j--)
	{
	    _HelpDrawBitMap(i,j,bitmap);
	    bitmap++;
	}
    }

void _HelpDrawBitMap(int i, int j, unsigned char *bitmap)
    {
    int k=1;
    for(k=0;k<8;k++)
	{
    	     if( (*bitmap)&MathPower(2,k) )
    		 {
    		 PCD8544_DrawPixel(j,(i*8)+k, PCD8544_Pixel_Set);
    		 }
    		else
    		 {
    		 PCD8544_DrawPixel(j,(i*8)+k, PCD8544_Pixel_Clear);
    		 }
    	 }
    }

int MathPower(int base, int power)
    {
    int i,result=1;
    if(power==0) return 1;
    else
	if(base==2)
	    {
	    return base<<(power-1);
	    }
	else
	    {
	    for(i=0;i<power;i++)
		result*=base;
	    return result;
	    }
    }

