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

    Fruit=GenerateFruit();
    while(GameStatus)
	{

	HeadSegment=GetSnakeHeadSegment();
	switch(GetButtonState()) 		//add collision with the wall
	    {
	    case Button_Left:
		{
		NewHeadSegment.x=HeadSegment.x-1;
		NewHeadSegment.y=HeadSegment.y;
		break;
		}
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
	    }
	//SetSnakeHeadSegment(NewHeadSegment);
	//RemoveLastTailSegment();

	//collisions with frame or body
	if(CheckCollisions(NewHeadSegment)==Collisions)
	    {
	    GameStatus=StopGame;
	    }

	//fruit
	if(CheckFruitCollisions(NewHeadSegment,Fruit)==Collisions)
	    {
	    AddSnakeSegmentAtTheEnd(NewHeadSegment);
	    Fruit=GenerateFruit();
	    }
	else
	    {
	    SetSnakeHeadSegment(NewHeadSegment);
	    RemoveLastTailSegment();
	    }

	DrawFilledBoxInGrid(Fruit.x,Fruit.y,PCD8544_Pixel_Set);
	DrawSnake();
	DrawFrame();
	PCD8544_Refresh();

	SetModifyFlag(NotModify);
	PCD8544_Delay(10000000);
	}//end while(GameStatus)

    DrawEndGameScreen();
    }
