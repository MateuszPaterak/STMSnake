#include "tm_stm32f4_pcd8544.h"

#define BOXDIMENSION 	4   // 4x4 pixels
#define BOXDIM 		BOXDIMENSION





/*
    Draw filled square
    x - coordinate of left top point
    y - coordinate of left top point

    Box dimension is stored in BOXDIMENSION

    PCD8544_Pixel_t color:
     - PCD8544_Pixel_Clear
     - PCD8544_Pixel_Set
*/
void  DrawFilledBox(unsigned char x, unsigned char y, PCD8544_Pixel_t color);


/*
 * Draw empty square frame
 * Box dimension is stored in BOXDIMENSION
 */
void DrawEmptyBox(unsigned char x, unsigned char y);

/*
 * Grid has 84/BOXDIMENSION width and         //   21x12, BOX=4
 * 	    48/BOXDIMENSION height	      //or 28x16, BOX=3
 */
void DrawFilledBoxInGrid(unsigned char x, unsigned char y, PCD8544_Pixel_t color);

/*
 * Grid has 84/BOXDIMENSION width and
 * 	    48/BOXDIMENSION height
 */
void DrawEmptyBoxInGrid(unsigned char x, unsigned char y);


/*
 * Draw bit map where bitmap is char[504],
 * and one char has inside 8 pixels upright and this is one line.
 * Display has 6x84 lines
 * From top left to bottom right corner
 */
void DrawBitMapVertical(unsigned char *bitmap);

/*
 * Flipped pictures!
 *
 * Draw bit map where bitmap is char[504],
 * and one char has inside 8 pixels upright and this is one line.
 * Display has 6x84 lines
 * From top left to bottom right corner
 */
void DrawBitMapVerticalFlipped(unsigned char *bitmap);

/*
 * Internal function for DrawBitMap
 */
void _HelpDrawBitMap(int i, int j, unsigned char *bitmap);

/*
 * Easy function for powers
 */
int MathPower(int base, int power);


