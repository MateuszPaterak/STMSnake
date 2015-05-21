#include "include.h"
#include "snake_engine.h"
#include "snake_game.h"
#include "TimerConfig.h"

#define HeightOfSelectionFrame 8
#define NumberOfPosition 4 		//main menu
#define NumberOfPositionSpeedMenu 5	//speed menu

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

			SetModifyFlag(NotModify);
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

//NumberOfAction == Number of current position
void SelectAction(unsigned char NumberOfAction)
    {
    switch(NumberOfAction)
	{
	    case 1:
		{
		StartSnakeGame();
		while(1)
		    {
		    if(GetModifyFlag()==Modify)
			{
			if(GetButtonState()==Button_Akcept)
			    {
			    SetModifyFlag(NotModify);
			    break;
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
		SpeedMenu();
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

void SpeedMenu()
    {
    InitStateButton2(Button_None);
    SetMenuPositions(1);
    unsigned char TmpMenuPositons=GetMenuPositions();

    DrawSpeedMenu();
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

			SetSpeedGame(GetMenuPositions());

			//TmpMenuPositons = 1;
			break;
			}

		    case Button_Up:
			{
			if(GetMenuPositions()==1)
			    {
			    TmpMenuPositons = NumberOfPositionSpeedMenu;
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
			if(GetMenuPositions()==NumberOfPositionSpeedMenu)
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

	if(GetButtonState()==Button_Akcept) //exit from menu after set speed
	    {
	    SetModifyFlag(NotModify);
	    break;
	    }

	SetMenuPositions(TmpMenuPositons);
	DrawSpeedMenu();
	DrawMenuSelectionFrame7x5(GetMenuPositions(),PCD8544_Pixel_Set);
	PCD8544_Refresh();
	SetModifyFlag(NotModify);
	    }//if

	}//while
    }//SpeedMenu

void DrawSpeedMenu()
    {
    PCD8544_Clear();
    PCD8544_GotoXY(1,1);
    PCD8544_Puts("0.10 s",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+HeightOfSelectionFrame);
    PCD8544_Puts("0.20 s",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+2*HeightOfSelectionFrame);
    PCD8544_Puts("0.30 s",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+3*HeightOfSelectionFrame);
    PCD8544_Puts("0.40 s",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+4*HeightOfSelectionFrame);
    PCD8544_Puts("0.50 s",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);
    }

void SetSpeedGame(unsigned char Position)
    {
    switch(Position)
	{
	case 1:
	    {
	    ConfTim3(200);
	    break;
	    }
	case 2:
	    {
	    ConfTim3(400);
	    break;
	    }
	case 3:
	    {
	    ConfTim3(600);
	    break;
	    }
	case 4:
	    {
	    ConfTim3(800);
	    break;
	    }
	case 5:
	    {
	    ConfTim3(1000);
	    break;
	    }
	default:
	    {
	    ConfTim3(1000);
	    break;
	    }
	}
    }

void DrawGameMainMenu()
    {
    PCD8544_Clear();
    PCD8544_GotoXY(1,1);
    PCD8544_Puts("Start gry",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+HeightOfSelectionFrame);
    PCD8544_Puts("Poziom trundos",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(1,1+2*HeightOfSelectionFrame);
    PCD8544_Puts("Najwyz. wyniki",PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

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
