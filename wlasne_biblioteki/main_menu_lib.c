#include "include.h"
#include "snake_engine.h"
#include "snake_game.h"

#define HeightOfSelectionFrame 8

MainMenuStatus StatusMenu;

void MainMenu()
    {
    InitStateButton2(Button_None);
    SetMenuPositions(1);
    unsigned char TmpMenuPositons=GetMenuPositions();

    DrawGameMainMenu();
    DrawMenuSelectionFrame7x5(GetMenuPositions(),PCD8544_Pixel_Set);
    PCD8544_Refresh();

    while(1)
	{
	if(GetModifyFlag()==Modify)
	{
		switch(GetButtonState())
		{
		    case Button_Akcept:
			{
			SetModifyFlag(NotModify);
			SetButtonState(Button_None);
			SelectAction(GetMenuPositions());

			//SetModifyFlag(NotModify);
			TmpMenuPositons = 1;
			break;
			}

		    case Button_Up:
			{
			if(GetMenuPositions()==1)
			    {
			    TmpMenuPositons = NumberOfPosition;
			    }
			else
			    {
			    TmpMenuPositons = GetMenuPositions();
			    TmpMenuPositons--;
			    }
			break;
			}

		    case Button_Down:
			{
			if(GetMenuPositions()==NumberOfPosition)
			    {
			    TmpMenuPositons = 1;
			    }
			else
			    {
			    TmpMenuPositons = GetMenuPositions();
			    TmpMenuPositons++;
			    }
			break;
			}

		    default:
			{
			break;
			}
		}//switch
	SetMenuPositions(TmpMenuPositons);
	DrawGameMainMenu();
	DrawMenuSelectionFrame7x5(GetMenuPositions(),PCD8544_Pixel_Set);
	PCD8544_Refresh();
	SetModifyFlag(NotModify);
	    }//if

	}//while
    }//MainMenu


void DrawGameMainMenu()
    {
    PCD8544_Clear();
    PCD8544_GotoXY(1,1);
    PCD8544_Puts("Start gry",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+HeightOfSelectionFrame);
    PCD8544_Puts("Poziom trundos",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+2*HeightOfSelectionFrame);
    PCD8544_Puts("Najwyzsze wyni",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+3*HeightOfSelectionFrame);
    PCD8544_Puts("Resetuj wyniki",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);
    }

void DrawMenuSelectionFrame7x5(unsigned char NumOfPosition, PCD8544_Pixel_t color)
    {
    unsigned char y0=(NumOfPosition-1)*HeightOfSelectionFrame;
    unsigned char y1=(NumOfPosition-1)*HeightOfSelectionFrame + HeightOfSelectionFrame;
    PCD8544_DrawRectangle(0,y0,83,y1,color);
    }

void SetMenuPositions(unsigned char Number)
    {
    StatusMenu.PositionNumber =Number;
    }
unsigned char GetMenuPositions()
    {
    return StatusMenu.PositionNumber;
    }

//NumberOfAction == Number of current position
void SelectAction(unsigned char NumberOfAction)
    {
    switch(NumberOfAction)
	{
	    case 1:
		{
		//unsigned char CheckButton=1;

		StartSnakeGame();

		//while(CheckButton==1)
		while(1)
		    {
		    if(GetModifyFlag()==Modify)
			{
			if(GetButtonState()==Button_Akcept)
			    {
			    SetModifyFlag(NotModify);
			    break;
			    //CheckButton=0;
			    }
			else
			    {
			    SetModifyFlag(NotModify);
			    }
			SetModifyFlag(NotModify);
			}//if 1

		    }//while
		break;
		}
	    case 2:
		{
		//Not yet implemented
		break;
		}
	    case 3:
		{
		//Not yet implemented
		break;
		}
	    case 4:
		{
		//Not yet implemented
		break;
		}
	}

    }
