#include "snakelib.h"
#include "snake_engine.h"
#include "include.h"
#include "stdio.h"
#include "snake_engine.h"

extern StateGame StateG;

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
//Filled- white or black!
void DrawFilledBoxInGrid(unsigned char xg, unsigned char yg, PCD8544_Pixel_t color) //ok
    {
    PCD8544_DrawFilledRectangle(xg*BOXDIM, yg*BOXDIM, xg*BOXDIM+BOXDIM-1, yg*BOXDIM+BOXDIM-1, color);
    }

void DrawEmptyBoxInGrid(unsigned char xg, unsigned char yg)//ok
    {
    PCD8544_DrawFilledRectangle(xg*BOXDIM, yg*BOXDIM, xg*BOXDIM+BOXDIM-1, yg*BOXDIM+BOXDIM-1, PCD8544_Pixel_Set);
    PCD8544_DrawFilledRectangle(xg*BOXDIM+1, yg*BOXDIM+1, xg*BOXDIM+BOXDIM -2 , yg*BOXDIM+BOXDIM -2 , PCD8544_Pixel_Clear);
    }

void DrawCrossInGrid(unsigned char xg, unsigned char yg, PCD8544_Pixel_t color)
    {
    PCD8544_DrawFilledRectangle(xg*BOXDIM, yg*BOXDIM, xg*BOXDIM+BOXDIM-1, yg*BOXDIM+BOXDIM-1, color);

	if(color==PCD8544_Pixel_Clear)
	{
	    PCD8544_DrawPixel(xg*BOXDIM, yg*BOXDIM,PCD8544_Pixel_Set);
	    PCD8544_DrawPixel(xg*BOXDIM+BOXDIM-1, yg*BOXDIM+BOXDIM-1,PCD8544_Pixel_Set);
	    PCD8544_DrawPixel(xg*BOXDIM, yg*BOXDIM+BOXDIM-1,PCD8544_Pixel_Set);
	    PCD8544_DrawPixel(xg*BOXDIM+BOXDIM-1, yg*BOXDIM,PCD8544_Pixel_Set);
	}
	else
	{
	    PCD8544_DrawPixel(xg*BOXDIM, yg*BOXDIM,PCD8544_Pixel_Clear);
	    PCD8544_DrawPixel(xg*BOXDIM+BOXDIM-1, yg*BOXDIM+BOXDIM-1,PCD8544_Pixel_Clear);
	    PCD8544_DrawPixel(xg*BOXDIM, yg*BOXDIM+BOXDIM-1,PCD8544_Pixel_Clear);
	    PCD8544_DrawPixel(xg*BOXDIM+BOXDIM-1, yg*BOXDIM,PCD8544_Pixel_Clear);
	}
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

//Widnows inside the frame
void ClearWindow()
    {
    PCD8544_DrawFilledRectangle(BOXDIM,BOXDIM,84-BOXDIM-1,48-BOXDIM-1,PCD8544_Pixel_Clear);
    }

void DrawFrame()
    {
    int i=0,j=1;
    for(;i<84/BOXDIMENSION;i++) //horizontal frame
	{
	 DrawFilledBoxInGrid(i,0,PCD8544_Pixel_Set);
	 DrawFilledBoxInGrid(i,(48/BOXDIM)-1,PCD8544_Pixel_Set);
	}
   for(;j<(48/BOXDIM)-1;j++) //vertical frame
    {
       DrawFilledBoxInGrid(0,j,PCD8544_Pixel_Set);
       DrawFilledBoxInGrid((84/BOXDIM)-1,j,PCD8544_Pixel_Set);
    }
    }

void DrawEndGameScreen()
    {
    char str[15];
    sprintf(str, "%d",GetPlayerPoints());

    PCD8544_Clear();
    PCD8544_GotoXY(15,12);
    PCD8544_Puts("Game Over",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);
    PCD8544_GotoXY(10,20);
    PCD8544_Puts("Your points:",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);
    PCD8544_GotoXY(34,28);
    PCD8544_Puts(str,PCD8544_Pixel_Set,PCD8544_FontSize_5x7);
    PCD8544_Refresh();
    }

void DrawSnake()
    {
    //PCD8544_Clear();

    unsigned char count=0;

    while(count<(StateG.LengthSnake-1))
	{
	DrawFilledBoxInGrid(StateG.SnakeSegments[count].x,StateG.SnakeSegments[count].y,PCD8544_Pixel_Set);
	count++;
	}
    if(count==(StateG.LengthSnake-1))				//special view of snake head (head is at the end of the table)
	{
	DrawEmptyBoxInGrid(StateG.SnakeSegments[count].x,StateG.SnakeSegments[count].y);
	count++;
	}
    //PCD8544_Refresh();
    }
