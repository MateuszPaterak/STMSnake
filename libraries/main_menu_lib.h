#ifndef __main_menu_lib_h
#define __main_menu_lib_h

#include "tm_stm32f4_pcd8544.h"

typedef struct
{
    unsigned char PositionNumber;	//value from 1 to NumberOfPosition
}MainMenuStatus;


void MainMenu(void);

/*
 *  Main Menu Snake's game
 */
void DrawGameMainMenu(void);

/*
 *  Draw mini frame around selected  menu's position
 *  PCD8544_Pixel_t color:
     - PCD8544_Pixel_Clear
     - PCD8544_Pixel_Set
 */
void DrawMenuSelectionFrame7x5(unsigned char NumOfPosition, PCD8544_Pixel_t Color);

void SpeedMenu(void);
void DrawSpeedMenu(void);
void SetSpeedGame(unsigned char Position);
void SetMenuPositions(unsigned char Number);
unsigned char GetMenuPositions(void);
void SelectAction(unsigned char NumberOfAction);

void HighScoresMenu(void);
void ChooseFileScore(unsigned char Position);
void DisplayScores(char * File);
void WaitForAcceptButton(void);

#endif //__main_menu_lib_h
