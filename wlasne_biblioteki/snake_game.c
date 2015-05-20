#include "include.h"
#include "snake_engine.h"

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
		continue;
	}

	HeadSegment=GetSnakeHeadSegment();

	if((GetButtonState()!=Button_None) || (GetButtonState()!=Button_Akcept)) //to safe button status before Pause, to know where are going after pause
	    {
	    ButtonStatusBeforePause=GetButtonState();
	    }

	switch(GetButtonState()) 		//add collision with the wall
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
/*	    case Button_Akcept:
		{
		SetModifyFlag(NotModify);
		SetButtonState(Button_None);
		RunPause();
		SetButtonState(ButtonStatusBeforePause);
		break;
		}*/
	    default:
		{
		break;
		}
	    }


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
	DrawSnake(); //attention-clear operation on the top
	DrawEmptyBoxInGrid(Fruit.x,Fruit.y);
	//DrawFrame();
	PCD8544_Refresh();

	SetModifyFlag(NotModify);
	PCD8544_Delay(6000000);
	}//end while(GameStatus)

    DrawEndGameScreen();
    }
