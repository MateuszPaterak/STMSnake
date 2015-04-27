#include "include.h"
#include "snake_engine.h"

void StartSnakeGame()
    {
    InitStateGame();
    InitStateButton();
    Coordinate HeadSegment;
    Coordinate NewHeadSegment;

    while(1)
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
	SetSnakeHeadSegment(NewHeadSegment);
	RemoveLastTailSegment();

	DrawSnake();

	SetModifyFlag(NotModify);
	PCD8544_Delay(10000000);
	}

    }
