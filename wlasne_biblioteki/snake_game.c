#include "include.h"
#include "snake_engine.h"

void StartSnakeGame()
    {
    InitStateGame();
    InitStateButton();
    Coordinate HeadSegment;
    Coordinate NewHeadSegment;
    Coordinate Fruit;
    GameState GameStatus=RunGame;

    DrawFrame();

    Fruit=GenerateFruit();
    while(GameStatus)
	{

	HeadSegment=GetSnakeHeadSegment();
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
	    }

	//collisions with frame or body
	if(CheckCollisions(NewHeadSegment)==Collisions)
	    {
	    GameStatus=StopGame;
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
	PCD8544_Delay(7500000);
	}//end while(GameStatus)

    DrawEndGameScreen();
    }
