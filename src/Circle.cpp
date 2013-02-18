#include "Mental_Mystics.h"

/**********************************************************
 * Function: glCircle3i
 * Purpose: draws filled circle at position and of size
 *********************************************************/
void glCircle3i(int x, int y, int radius) { 
    
	glBegin(GL_POLYGON);
	for (int angle = 0; angle < 360; angle ++) glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
	glEnd();
}  