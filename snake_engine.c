#include "snake_engine.h"
#include "stdlib.h"
#include "tm_stm32f4_pcd8544.h"
#include "snakelib.h"
#include "stm32f4xx_rng.h"
#include "stm32f4xx_tim.h"
#include "ff.h"


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
void DeInitStateGame(void)
    {
    free(StateG.SnakeSegments);
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

unsigned char GetPlayerPoints(void)
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



CollisionsState CheckCollisions(Coordinate Segment)
    {
    if(Segment.x>0 && Segment.x<20 && Segment.y>0 && Segment.y<11) //check collisions with a frame
	{
	unsigned char LengthCount =1;
	Coordinate tmp;
	do							//check collisions with the body of a snake
	{
	    //tmp = GetSnakeSegment(LengthCount-1);
	    tmp = GetSnakeSegment(LengthCount);			//first moves the tail, then head :)
	    if(tmp.x==Segment.x && tmp.y==Segment.y)
		{
		return Collisions;
		}
	    LengthCount++;
	}while(LengthCount!=GetLengthSnake());
	return NoCollisions;
	}
    else
	{
	return Collisions;
	}
    }

CollisionsState CheckFruitCollisions(Coordinate SnakeSegment, Coordinate Fruit)
    {
    if(SnakeSegment.x ==Fruit.x && SnakeSegment.y==Fruit.y)
	{
	return Collisions;
	}
    else
	{
	return NoCollisions;
	}
    }

//check collisions with a second segment(detect reversed direction)
Coordinate CheckAndCorretReversedDirection(Coordinate NewHeadSegment)
    {
    Coordinate HeadSegment = GetSnakeHeadSegment();
    Coordinate SecondSemgnet = GetSnakeSegment(GetLengthSnake()-2);
    Coordinate TmpSegment;

    if((SecondSemgnet.x==NewHeadSegment.x) && (SecondSemgnet.y==NewHeadSegment.y))
	{
	if(NewHeadSegment.x == HeadSegment.x)//up-down
	    {
	    TmpSegment.x=HeadSegment.x;
	    if(HeadSegment.y-NewHeadSegment.y==1) //calculate new y coordination
		{
		TmpSegment.y=HeadSegment.y+1;
		}
	    else
		{
		TmpSegment.y=HeadSegment.y-1;
		}
	    return TmpSegment;
	    }//end if2
	else//left-right
	    {
	    TmpSegment.y=HeadSegment.y;
	    if(HeadSegment.x-NewHeadSegment.x==1) //calculate new y coordination
		{
		TmpSegment.x=HeadSegment.x+1;
		}
	    else
		{
		TmpSegment.x=HeadSegment.x-1;
		}
	    return TmpSegment;
	    }//end else2
	}//end if1
    else
	{
	return NewHeadSegment;
	}//else if1
    }//CheckReversedDirection

//Second version
Coordinate CheckAndCorretReversedDirection2(Coordinate NewHeadSegment)
    {
    Coordinate HeadSegment = GetSnakeHeadSegment();
    Coordinate SecondSemgnet = GetSnakeSegment(GetLengthSnake()-2);
    Coordinate TmpSegment;

    if((SecondSemgnet.x==NewHeadSegment.x) && (SecondSemgnet.y==NewHeadSegment.y))
	{
	switch(GetButtonState())
	    {
	    case Button_Up:
		{
		TmpSegment.x=HeadSegment.x;
		TmpSegment.y=HeadSegment.y+1;
		return TmpSegment;
		break;
		}
	    case Button_Down:
		{
		TmpSegment.x=HeadSegment.x;
		TmpSegment.y=HeadSegment.y-1;
		return TmpSegment;
		break;
		}
	    case Button_Left:
		{
		TmpSegment.y=HeadSegment.y;
		TmpSegment.x=HeadSegment.x+1;
		return TmpSegment;
		break;
		}
	    case Button_Right:
		{
		TmpSegment.y=HeadSegment.y;
		TmpSegment.x=HeadSegment.x-1;
		return TmpSegment;
		break;
		}
	    default:
		{
		return NewHeadSegment;
		}
	    }//switch
	}//end if1
    else
	{
	return NewHeadSegment;
	}//else if1

    }//end function

Coordinate GenerateFruit()
    {
    uint32_t rng_x,rng_y;
    unsigned char LengthCount =0;
    Coordinate tmp;
    Coordinate fruit;

    while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET)   {}
    rng_x = RNG_GetRandomNumber() % ((84/BOXDIM)-2);
    rng_x++; //frame :)

    while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET)   {}
    rng_y = RNG_GetRandomNumber() % ((48/BOXDIM)-2);
    rng_y++;

    do							//compare fruit coordinate with the body of snake
    	{
    	    tmp = GetSnakeSegment(LengthCount);

    	    if(tmp.x==rng_x && tmp.y==rng_y)
    		{
    		while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET)    {}
    		rng_x = RNG_GetRandomNumber() % ((84/BOXDIM)-2);
    		rng_x++;

    		while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET)   {}
    		rng_y = RNG_GetRandomNumber() % ((48/BOXDIM)-2);
    		rng_y++;

    		LengthCount = 0;
    		}
    	    else {
    		{
    		LengthCount++;
    		}
	    }

    	}while(LengthCount<=(GetLengthSnake()-1)); //to check

    fruit.x=rng_x;
    fruit.y=rng_y;
    return(fruit);
    }

char RunPause(void)
    {
	while(1)
	    {
	    if(GetModifyFlag()==Modify)
		{
		switch(GetButtonState())
		    {
		    case Button_Akcept:
		    case Button_Up:
		    case Button_Down:
		    case Button_Left:
		    case Button_Right:
			{
			    SetModifyFlag(NotModify);
			    SetButtonState(Button_None);
			    return 0;
			    break;
			}
		    default:
			{
			break;
			}
		    }//switch

		SetModifyFlag(NotModify);
		}
	    }
    }
//End StateGame struct



/*
 * StateButton struct
 */
void InitStateButton(void) //set name to "SetInitStateButton"
    {
    Button.Button=Button_Right;
    Button.ModifyFlag=NotModify;
    }
void InitStateButton2(ButtonState BuSt) //set name to "SetStateButton"
    {
    Button.Button=BuSt;
    Button.ModifyFlag=NotModify;
    }
/*
 * ButtonState:
 * 	-Button_Left
 *	-Button_Up
 *	-Button_Right
 *	-Button_Down
 *	-Button_Akcept
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

void TimerLoop()
    {
    TIM_Cmd(TIM3, ENABLE);
    unsigned char flag=1;

    while(flag)
	{
	if(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update))
	    {
	    flag=0;
	    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	    }
	}//while

    TIM_Cmd(TIM3, DISABLE);
    }

void SaveResult()
    {
    #define PLAYER_CHAR 4	//3xchar (nick) +  1xchar (points)
					    //player number: first player = 0, second = 1, third = 2
    unsigned char TabTemp[12] = {0}; //3 position x 4char
    unsigned char TabPlayer[4];

    FATFS fatfs;
    FIL plik;
    FRESULT fresult;
    UINT odczytane_bajty;

    char file[6]="FILE";
    file[4]=GetSnakeSpeed()+48;
    file[5]=0;


    fresult = f_mount( 0, &fatfs );
    fresult = f_open( &plik, (const char * )file, FA_OPEN_ALWAYS |  FA_READ );
    if( fresult == FR_OK )
    {
	    f_lseek(&plik,0); //przesuniêcie kursora na pocz¹tek pliku
	    fresult = f_read( &plik, TabTemp, 12, &odczytane_bajty); //odczyt danych
	    fresult = f_close( &plik );

	    unsigned char i;

	    switch(odczytane_bajty)
		{
		      case 0: //0 players and save to first position
			  {
			  GetNickAndScores(TabPlayer);
			  WriteResultToSd(TabPlayer, 4);
			  break;
			  }
		      case 4: //1 players
			  {
			  if(TabTemp[3]>=GetPlayerPoints())
			      {//when SD_Player >= New_Player

			      GetNickAndScores(TabPlayer);

			      for(i=0;i<4;i++)
				  {
				  TabTemp[i+4]=TabPlayer[i];
				  }
			      }
			  else//when SD_Player < New_Player
			      {
			      GetNickAndScores(TabPlayer);
			      CopyPlayerInTempTab(TabTemp,0,1);

			      for(i=0;i<4;i++)
				  {
				  TabTemp[i]=TabPlayer[i];
				  }

			      }
			      WriteResultToSd(TabTemp, 8);

			  break;
			  }

		      case 8: //2 players
			  {
			  if(TabTemp[7]>=GetPlayerPoints())
			      {//when SD_Player2 >= New_Player

			      GetNickAndScores(TabPlayer);

			      for(i=0;i<4;i++)
				  {
				  TabTemp[i+8]=TabPlayer[i];
				  }
			      }
			  else //when SD_Player2 < New_Player
			      {
			      CopyPlayerInTempTab(TabTemp,1,2);
			      GetNickAndScores(TabPlayer);

			      if(TabTemp[3]>=GetPlayerPoints())
				  {//when SD_Player1 >= New_Player

				      for(i=0;i<4;i++)
					  {
					  TabTemp[i+4]=TabPlayer[i];
					  }
				  }
				  else
				  {//when SD_Player1 < New_Player

				      CopyPlayerInTempTab(TabTemp,0,1);

				      for(i=0;i<4;i++)
					  {
					  TabTemp[i]=TabPlayer[i];
					  }
				  }
			      }

			  WriteResultToSd(TabTemp, 12);
			  break;
			  }

		      case 12: //3 players
			  {
			  if(TabTemp[11]>=GetPlayerPoints())
			      {//when SD_Player3 >= New_Player

			      }
			      else //when SD_Player3 < New_Player
				  {

				  if(TabTemp[7]>=GetPlayerPoints())
				      {//when SD_Player2 >= New_Player

				      GetNickAndScores(TabPlayer);

				      for(i=0;i<4;i++)
					  {
					  TabTemp[i+8]=TabPlayer[i];
					  }
				      }
				  else //when SD_Player2 < New_Player
				      {
				      CopyPlayerInTempTab(TabTemp,1,2);
				      GetNickAndScores(TabPlayer);

				      if(TabTemp[3]>=GetPlayerPoints())
					  {//when SD_Player1 >= New_Player

					      for(i=0;i<4;i++)
						  {
						  TabTemp[i+4]=TabPlayer[i];
						  }
					  }
					  else
					  {//when SD_Player1 < New_Player

					      CopyPlayerInTempTab(TabTemp,0,1);

					      for(i=0;i<4;i++)
						  {
						  TabTemp[i]=TabPlayer[i];
						  }
					  }//else3
				      }//else2
				  }//else1

			  WriteResultToSd(TabTemp, 12);
			  break;
			  }

		      default: //error
			  {
			  break;
			  }
		}//switch

    }//if fresult == FR_OK
    else
	{
	//SD Modul is empty
	}

}

void CopyPlayerInTempTab(unsigned char *Tab, unsigned char SourcePlayer, unsigned char DestinationPlayer)
    {
    //number of (source/destination) position players in table
    //number from 0 to 2

	char tmp = 0;
	for(;tmp<PLAYER_CHAR;tmp++)
	{
	Tab[DestinationPlayer*PLAYER_CHAR + tmp] = Tab[SourcePlayer*PLAYER_CHAR + tmp];
	}
    }

void GetNickAndScores(unsigned char * TabPlayer)
    {
    char PositionInNick=1;
    char Nick[4]="AAA";
    char TmpChar=65;
    //const char StartChar=65; //65=='A'
    //const char EndChar=90;   //90=='Z'

    InitStateButton2(Button_None);

    SetModifyFlag(NotModify);
    PCD8544_Clear();
    PCD8544_GotoXY(33,20);
    PCD8544_Puts(Nick,PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

    PCD8544_GotoXY(31+(PositionInNick-1)*6,30);
    PCD8544_DrawLine(31+(PositionInNick-1)*6,30,33+(PositionInNick)*6,30,PCD8544_Pixel_Set);

    PCD8544_Refresh();

    while(PositionInNick<4)
	{
		if(GetModifyFlag()==Modify)
		{
			switch(GetButtonState())
			{
			    case Button_Akcept:
				{
				Nick[PositionInNick-1]=TmpChar;

				PositionInNick++;
				TmpChar=65;
				break;
				}

			    case Button_Up:
				{
				if(TmpChar==90)
				    {
				    TmpChar=65;
				    }
				else
				    {
				    TmpChar++;
				    }
				Nick[PositionInNick-1]=TmpChar;
				break;
				}

			    case Button_Down:
				{
				if(TmpChar==65)
				    {
				    TmpChar=90;
				    }
				else
				    {
				    TmpChar--;
				    }
				Nick[PositionInNick-1]=TmpChar;
				break;
				}

			    default:
				{
				break;
				}
			}//switch

		SetModifyFlag(NotModify);
		PCD8544_Clear();
	        PCD8544_GotoXY(33,20);
		PCD8544_Puts(Nick,PCD8544_Pixel_Set,PCD8544_FontSize_5x7);

		PCD8544_GotoXY(31+(PositionInNick-1)*6,30);
		PCD8544_DrawLine(31+(PositionInNick-1)*6,30,32+(PositionInNick)*6,30,PCD8544_Pixel_Set);

		PCD8544_Refresh();

		}//if GetModifyFlag()==Modify
	}//while - PositionInNick

    TabPlayer[0]=Nick[0];
    TabPlayer[1]=Nick[1];
    TabPlayer[2]=Nick[2];
    TabPlayer[3]=GetPlayerPoints();
    }

void WriteResultToSd(unsigned char * Tab, char BytesToSave)
    {
	FATFS fatfs;
	FIL plik;
	FRESULT fresult;
	UINT SavedBytes;

	char file[6]="FILE";
	file[4]=GetSnakeSpeed()+48;
	file[5]=0;


	fresult = f_mount( 0, &fatfs );
	fresult = f_open( &plik, (const char * )file, FA_OPEN_ALWAYS | FA_WRITE );
	if( fresult == FR_OK )
	{
		f_lseek(&plik,0); //przesuniêcie kursora na pocz¹tek pliku
		fresult = f_write( &plik, Tab, (UINT) BytesToSave, &SavedBytes);
	}
	fresult = f_close( &plik );

    }



