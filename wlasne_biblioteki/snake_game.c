#include "include.h"
#include "snake_engine.h"
#include "TimerConfig.h"

void StartSnakeGame()
    {
    InitStateGame();
    InitStateButton();
    Coordinate HeadSegment;
    Coordinate NewHeadSegment;
    Coordinate Fruit;
    GameStatus GameSt=RunGame;
    ButtonState ButtonStatusBeforePause;

    DrawFrame();

    Fruit=GenerateFruit();
    while(GameSt)
	{
	if(GetButtonState()==Button_Akcept)
	{
		SetModifyFlag(NotModify);
		SetButtonState(Button_None);
		RunPause();
		SetButtonState(ButtonStatusBeforePause);
		//continue;
	}
	if((GetButtonState()!=Button_None) && (GetButtonState()!=Button_Akcept)) //to safe button status before Pause, to know where are going after pause
	    {
	    ButtonStatusBeforePause=GetButtonState();
	    }

	HeadSegment=GetSnakeHeadSegment();
	switch(GetButtonState())
	    {
	    case Button_Up:
		{
		NewHeadSegment.x=HeadSegment.x;
		NewHeadSegment.y=HeadSegment.y-1;
		break;
		}
	    case Button_Right:
		{
		NewHeadSegment.x=HeadSegment.x+1;
		NewHeadSegment.y=HeadSegment.y;
		break;
		}
	    case Button_Down:
		{
		NewHeadSegment.x=HeadSegment.x;
		NewHeadSegment.y=HeadSegment.y+1;
		break;
		}
	    case Button_Left:
	    	{
	    	NewHeadSegment.x=HeadSegment.x-1;
	    	NewHeadSegment.y=HeadSegment.y;
	    	break;
	    	}
	    default:
		{
		break;
		}
	    }

	//remove possibility reversed direction(with body)
	NewHeadSegment=CheckAndCorretReversedDirection2(NewHeadSegment);


	//collisions with frame or body
	if(CheckCollisions(NewHeadSegment)==Collisions)
	    {
	    GameSt=StopGame;
	    }

	//collisions with fruit
	if(CheckFruitCollisions(NewHeadSegment,Fruit)==Collisions)
	    {
	    AddSnakeSegmentAtTheEnd(NewHeadSegment);
	    Fruit=GenerateFruit();
	    SetPlayerPoints(GetPlayerPoints()+3);//add points for eating fruit
	    }
	else
	    {
	    SetSnakeHeadSegment(NewHeadSegment);
	    RemoveLastTailSegment();
	    }

	ClearWindow();
	DrawSnake();
	DrawCrossInGrid(Fruit.x,Fruit.y,PCD8544_Pixel_Set);
	//DrawEmptyBoxInGrid(Fruit.x,Fruit.y);
	PCD8544_Refresh();

	SetModifyFlag(NotModify);
	TimerLoop();
	}//end while(GameStatus)

    DeInitStateGame();
    DrawEndGameScreen();
    }
