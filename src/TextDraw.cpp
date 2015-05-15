#include "Mental_Mystics.h"
#include <string.h>

/**********************************************************
 * Function: drawTextCentered
 * Purpose: draws text centered at a given point
 *********************************************************/
void drawTextTitle(int centerX, int centerY, char* text){
		
	int length = strlen(text);
	int x = centerX - 24*length/2;
	int y = centerY;
	int index;
	glColor3f (0.0f, 0.0f, 0.0f);
	
	for(index = 0; index < length; index++, x += 22){
		glRasterPos2f(x, y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[index]);
	}
}

/**********************************************************
 * Function: drawText1
 * Purpose: draws text centered at a given point
 *********************************************************/
void drawText12(int centerX, int centerY, char* text){
		
	int length = strlen(text);
	int x = centerX - 12*length/2;
	int y = centerY;
	int index;
	
	for(index = 0; index < length; index++, x += 12){
		glRasterPos2f(x, y);
		glColor3f (0.0f, 0.0f, 0.0f);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[index]);
	}
}
	
/**********************************************************
 * Function: drawText18
 * Purpose: draws text centered at a given point
 *********************************************************/
void drawText15(int centerX, int centerY, char* text){
		
	int length = strlen(text), x = centerX - 15*length/2, y = centerY, index;
	
	for(index = 0; index < length; index++, x += 15){
		glRasterPos2f(x, y);
		glColor3f (0.0f, 0.0f, 0.0f);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[index]);
	}
}
