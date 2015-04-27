#ifndef _structcoordinate
#define _structcoordinate
#define MAX_LENGTH_SNAKE 252

typedef struct
    {
     unsigned char x;
     unsigned char y;
 }Coordinate;


typedef struct
{
    Coordinate *SnakeSegments;//table with snake's segments [0]-tail [LenghtSnake-1]-head
    unsigned int PlayerPoints;
    unsigned char LengthSnake;
    unsigned char SnakeSpeed;
}StateGame;

typedef struct
{
    unsigned char ModifyFlag;
    unsigned char Button;
}StateButton;

typedef enum{
    NotModify=0,
    Modify = !NotModify
}ModifyFlagStatus;

typedef enum{
    Button_Left=0,
    Button_Up=1,
    Button_Right=2,
    Button_Down=3,
}ButtonState;

#endif

//StateGame struct
void InitStateGame(void);
void AddSnakeSegmentAtTheEnd(Coordinate Segment);
void SetSnakeSegment(unsigned int Index,Coordinate Segment);
Coordinate GetSnakeSegment(unsigned int Index);
void SetLengthSnake(unsigned char Length);
unsigned char GetLengthSnake(void);
void SetPlayerPoints(unsigned int points);
unsigned int GetPlayerPoints(void);
void SetSnakeSpeed(unsigned char Speed);
unsigned char GetSnakeSpeed();
void SetSnakeHeadSegment(Coordinate Segment);
Coordinate GetSnakeHeadSegment();
void RemoveLastTailSegment();
void DrawSnake();

//StateButton struct
void InitStateButton(void);
void SetButtonState(ButtonState But);
ButtonState GetButtonState(void);
void SetModifyFlag(ModifyFlagStatus Flag);
ModifyFlagStatus GetModifyFlag(void);
