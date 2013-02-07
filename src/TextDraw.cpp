#include "Mental_Mystics.h"
#include <string.h>

/**********************************************************
 * Function: drawTextCentered
 * Purpose: draws text centered at a given point
 *********************************************************/
void drawTextCentered(int centerX, int centerY, char* text){
		
	int length = strlen(text);
	int x = centerX - 24*length/2;
	int y = centerY;
	int index;
	
	for(index = 0; index < length; index++, x += 22){
		glRasterPos2f(x, y);
		glColor3f (0.0f, 0.0f, 0.0f);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[index]);
	}
}
	
	