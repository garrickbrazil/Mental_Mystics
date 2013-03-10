#include "Mental_Mystics.h"

/**********************************************************
 * Function: drawMissingPeg
 * Purpose: draws missing peg illusion
 *********************************************************/
void drawMissingPeg(int startX, int startY, int sizeX, int sizeY){
	
	glColor3f(0.0f, 0.0f, 0.0f);
	
	glLineWidth(2.5);
	
	// Circle size
	int circleRadX = sizeX*.038/2;
	int circleRadY = sizeY*.1/2;
	
	// Circle positions
	int circle1X = startX + sizeX*.065;
	int circle2X = startX + sizeX*.13;
	int circle3X = startX + sizeX*.195;
	
	int circle1Y = startY + sizeY*.58;
	int circle2Y = startY + sizeY*.58 - 2*circleRadY*1.85;
	int circle3Y = startY + sizeY*.58 - 4*circleRadY*1.85;
	
	
	// Draw 3 circles
	glEllipse4i(circle1X + circleRadX, circle1Y + circleRadY, circleRadX, circleRadY);
	glEllipse4i(circle2X + circleRadX, circle2Y + circleRadY, circleRadX, circleRadY);
	glEllipse4i(circle3X + circleRadX, circle3Y + circleRadY, circleRadX, circleRadY);
	
	// Line1 (Top Peg1)
	glBegin(GL_LINES);
	glVertex3f(circle1X + circleRadX, circle1Y + circleRadY*2, 0.0);
	glVertex3f(startX + sizeX*.74, startY + sizeY*.90, 0);
	glEnd();
	
	// Line2 (Bottom Peg1)
	glBegin(GL_LINES);
	glVertex3f(circle1X + circleRadX, circle1Y, 0.0);
	glVertex3f(startX + sizeX*.74 - circleRadX*2, startY + sizeY*.90 - circleRadY*2, 0);
	glEnd();
	
	// Line3 (Vertical Peg1 to Peg2)
	glBegin(GL_LINES);
	glVertex3f(startX + sizeX*.74 - circleRadX*2, startY + sizeY*.90 - circleRadY*2, 0);
	glVertex3f(startX + sizeX*.74 - circleRadX*2, startY + sizeY*.90 - 2*circleRadY*1.85, 0);
	glEnd();
	
	// Line 4 (Top Peg2)
	glBegin(GL_LINES);
	glVertex3f(circle2X + circleRadX, circle2Y + circleRadY*2, 0.0);
	glVertex3f(startX + sizeX*.74 - circleRadX*2, startY + sizeY*.90 - 2*circleRadY*1.85, 0);
	glEnd();
	
	// Line 5 (Top Peg3)
	glBegin(GL_LINES);
	glVertex3f(circle3X + circleRadX, circle3Y + circleRadY*2, 0.0);
	glVertex3f((startX + sizeX*.96), (startY + sizeY*.62), 0);
	glEnd();
	
	// Line 6 (Bottom Peg3)
	glBegin(GL_LINES);
	glVertex3f(circle3X + circleRadX, circle3Y, 0.0);
	glVertex3f((startX + sizeX*.96), (startY + sizeY*.62) - circleRadY*2, 0);
	glEnd();
	
	// Line 7 (Vertical Peg2 to Peg3)
	glBegin(GL_LINES);
	glVertex3f((startX + sizeX*.96), (startY + sizeY*.62), 0);
	glVertex3f((startX + sizeX*.96), (startY + sizeY*.62) - circleRadY*2, 0);
	glEnd();
	
	// Line8 (Peg1 to Peg3)
	glBegin(GL_LINES);
	glVertex3f(startX + sizeX*.74, startY + sizeY*.90, 0);
	glVertex3f((startX + sizeX*.96), (startY + sizeY*.62), 0);
	glEnd();
	
	// Line9 (Bottom Peg2)
	glBegin(GL_LINES);
	glVertex3f(circle2X + circleRadX, circle2Y, 0.0);
	glVertex3f(startX + sizeX*.805, startY + sizeY*.67, 0);
	glEnd();
	
	// Line10 (top middle square)
	glBegin(GL_LINES);
	glVertex3f(startX + sizeX*.74 - circleRadX*2, startY + sizeY*.90 - circleRadY*2, 0);
	glVertex3f(startX + sizeX*.805, startY + sizeY*.67, 0);
	glEnd();
	
	// Line11 (bottom middle square)
	glBegin(GL_LINES);
	glVertex3f(startX + sizeX*.74 - circleRadX*2, startY + sizeY*.90 - 2*circleRadY*1.85, 0);
	glVertex3f(startX + sizeX*.757, startY + sizeY*.649, 0);
	glEnd();
	
}
