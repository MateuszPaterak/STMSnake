#include "snake_engine.h"
#include "stdlib.h"
#include "tm_stm32f4_pcd8544.h"
#include "snakelib.h"

//Coordinate SnakeSegments[252]; //or in StateGame struct with dynamic alocation memory
StateButton 	Button;
StateGame 	StateG;

/*
 * StateGame struct
 */
void InitStateGame(void)
    {
    StateG.SnakeSegments=calloc(MAX_LENGTH_SNAKE,sizeof(Coordinate));
    StateG.LengthSnake=0; //3
    StateG.PlayerPoints=0;

    //Set the initial positions configuration
    Coordinate S1,S2,S3;
    S1.x=3;
    S1.y=5;
    S2.x=4;
    S2.y=5;
    S3.x=5;
    S3.y=5;
    AddSnakeSegmentAtTheEnd(S1);
    AddSnakeSegmentAtTheEnd(S2);
    AddSnakeSegmentAtTheEnd(S3);
    }

void AddSnakeSegmentAtTheEnd(Coordinate Segment)
    {
    if(StateG.LengthSnake!=MAX_LENGTH_SNAKE)
	{
	StateG.SnakeSegments[StateG.LengthSnake]=Segment;
	StateG.LengthSnake++;
	}
    }

void SetSnakeSegment(unsigned int Index,Coordinate Segment)
    {
    StateG.SnakeSegments[Index]=Segment;
    }

Coordinate GetSnakeSegment(unsigned int Index)
    {
    return StateG.SnakeSegments[Index];
    }

void SetLengthSnake(unsigned char Length)
    {
    StateG.LengthSnake=Length;
    }

unsigned char GetLengthSnake(void)
    {
    return StateG.LengthSnake;
    }

void SetPlayerPoints(unsigned int points)
    {
    StateG.PlayerPoints=points;
    }

unsigned int GetPlayerPoints(void)
    {
    return StateG.PlayerPoints;
    }

void SetSnakeSpeed(unsigned char Speed)
    {
    StateG.SnakeSpeed=Speed;
    }

unsigned char GetSnakeSpeed()
    {
    return StateG.SnakeSpeed;
    }

void SetSnakeHeadSegment(Coordinate Segment)
    {
    if(StateG.LengthSnake!=MAX_LENGTH_SNAKE)
	{
	StateG.SnakeSegments[StateG.LengthSnake]=Segment;
	}
    }

Coordinate GetSnakeHeadSegment()
    {
    return StateG.SnakeSegments[StateG.LengthSnake-1];
    }

//and move one position to left
void RemoveLastTailSegment()
    {
    unsigned char count=0;
    while(count<StateG.LengthSnake)
	{
	StateG.SnakeSegments[count]=StateG.SnakeSegments[count+1];
	count++;
	}
    }

void DrawSnake()
    {
    PCD8544_Clear();

    unsigned char count=0;
    while(count<StateG.LengthSnake)
	{
	DrawFilledBoxInGrid(StateG.SnakeSegments[count].x,StateG.SnakeSegments[count].y,PCD8544_Pixel_Set);
	count++;
	}
    PCD8544_Refresh();
    }
//End StateGame struct



/*
 * StateButton struct
 */
void InitStateButton(void)
    {
    Button.Button=Button_Right;
    Button.ModifyFlag=NotModify;
    }
/*
 * ButtonState:
 * 	-Button_Left
 *	-Button_Up
 *	-Button_Right
 *	-Button_Down
 */
void SetButtonState(ButtonState But)
    {
    Button.Button=But;
    }

ButtonState GetButtonState(void)
    {
    return Button.Button;
    }

/*
 * ModifyFlagStatus:
 * 	-Modify
 * 	-NotModify
*/
void SetModifyFlag(ModifyFlagStatus Flag)
    {
    Button.ModifyFlag=Flag;
    }

ModifyFlagStatus GetModifyFlag(void)
    {
    return Button.ModifyFlag;
    }
// End StateButton struct
