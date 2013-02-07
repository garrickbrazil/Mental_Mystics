#include "Mental_Mystics.h"

/**********************************************************
 * Function: drawDiamond
 * Purpose: draws a diamond at location and with size
 *********************************************************/
void drawDiamond(GLintPoint center, int size){
	
	glColor3f(0.0f, 0.0f, 0.0f);
	
	glBegin(GL_LINE_LOOP);
	glVertex2i(center.x , center.y + size/2);
	glVertex2i(center.x + size/2, center.y);
	glVertex2i(center.x , center.y - size/2);
	glVertex2i(center.x - size/2, center.y);
	glEnd();
}