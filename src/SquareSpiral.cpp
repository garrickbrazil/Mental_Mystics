#include "Mental_Mystics.h"

/**********************************************************
 * Function: drawSquareSpiral
 * Purpose: draws square spiral illusion
 *********************************************************/
void drawSquareSpiral(int startX, int startY, int sizeX, int sizeY){
	
	glLineWidth(2.75);
	startX = WIDTH/2 - sizeY/2;
	
	// Grey background
	glColor3f(0.6f, 0.6f, 0.6f);
	glRecti(startX, startY, startX + sizeX, startY + sizeY);
	
	bool odd;
	
	double radSq = sizeY/40;
	
	double rad1X = sizeX*.9/2.0,
		rad2X = sizeX*.7/2.0,
		rad3X = sizeX*.5/2.0,
		rad4X = sizeX*.3/2.0;
		
	double rad1Y = sizeY*.9/2.0,
		rad2Y = sizeY*.7/2.0,
		rad3Y = sizeY*.5/2.0,
		rad4Y = sizeY*.3/2.0;
	
	double deg2rad = 3.14/180;
		
	odd = true;
	
	// Circle 1
	for (double angle = 0, useAngle = 60; angle < 360; angle+=6, useAngle -=6/1){
	
		if(odd) glColor3f(0, 0,0);
		else glColor3f(1, 1, 1.0);
		odd = !odd;
		
		if(useAngle<=-90) useAngle += 90;
		
		glBegin(GL_LINE_LOOP);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad1X + radSq  + cos(useAngle*deg2rad)*radSq           , startY + sizeY/2 + cos(angle*deg2rad) * rad1Y - radSq      + sin(useAngle*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad1X + radSq  + cos((useAngle + 90)*deg2rad)*radSq    , startY + sizeY/2 + cos(angle*deg2rad) * rad1Y - radSq      + sin((useAngle + 90)*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad1X + radSq  + cos((useAngle + 180)*deg2rad)*radSq   , startY + sizeY/2 + cos(angle*deg2rad) * rad1Y - radSq      + sin((useAngle + 180)*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad1X + radSq  + cos((useAngle + 270)*deg2rad)*radSq   , startY + sizeY/2 + cos(angle*deg2rad) * rad1Y - radSq      + sin((useAngle + 270)*deg2rad)*radSq);
		glEnd();
		//if(angle < 180) useAngle -= 180;
	}
	
	odd = false;
	
	// Circle 2
	for (double angle = 0, useAngle = -60; angle < 360; angle+=7.5, useAngle -=7.5/1){
	
		if(odd) glColor3f(0, 0,0);
		else glColor3f(1, 1, 1.0);
		odd = !odd;
		
		if(useAngle<=-90) useAngle += 90;
		
		glBegin(GL_LINE_LOOP);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad2X + radSq  + cos(useAngle*deg2rad)*radSq           , startY + sizeY/2 + cos(angle*deg2rad) * rad2Y - radSq      + sin(useAngle*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad2X + radSq  + cos((useAngle + 90)*deg2rad)*radSq    , startY + sizeY/2 + cos(angle*deg2rad) * rad2Y - radSq      + sin((useAngle + 90)*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad2X + radSq  + cos((useAngle + 180)*deg2rad)*radSq   , startY + sizeY/2 + cos(angle*deg2rad) * rad2Y - radSq      + sin((useAngle + 180)*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad2X + radSq  + cos((useAngle + 270)*deg2rad)*radSq   , startY + sizeY/2 + cos(angle*deg2rad) * rad2Y - radSq      + sin((useAngle + 270)*deg2rad)*radSq);
		glEnd();
		
	}
	
	odd = true;
	
	// Circle 3
	for (double angle = 0, useAngle = 60; angle < 360; angle+=12, useAngle -=12/1){
	
		if(odd) glColor3f(0, 0,0);
		else glColor3f(1, 1, 1.0);
		odd = !odd;
		
		if(useAngle<=-90) useAngle += 90;
		
		glBegin(GL_LINE_LOOP);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad3X + radSq  + cos(useAngle*deg2rad)*radSq           , startY + sizeY/2 + cos(angle*deg2rad) * rad3Y - radSq      + sin(useAngle*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad3X + radSq  + cos((useAngle + 90)*deg2rad)*radSq    , startY + sizeY/2 + cos(angle*deg2rad) * rad3Y - radSq      + sin((useAngle + 90)*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad3X + radSq  + cos((useAngle + 180)*deg2rad)*radSq   , startY + sizeY/2 + cos(angle*deg2rad) * rad3Y - radSq      + sin((useAngle + 180)*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad3X + radSq  + cos((useAngle + 270)*deg2rad)*radSq   , startY + sizeY/2 + cos(angle*deg2rad) * rad3Y - radSq      + sin((useAngle + 270)*deg2rad)*radSq);
		glEnd();
		
	}
	
	odd = false;
	
	// Circle 4
	for (double angle = 0, useAngle = -60; angle < 360; angle+=20, useAngle -=20/1){
	
		if(odd) glColor3f(0, 0,0);
		else glColor3f(1, 1, 1.0);
		odd = !odd;
		if(useAngle<=-90) useAngle += 90;
		
		glBegin(GL_LINE_LOOP);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad4X + radSq  + cos(useAngle*deg2rad)*radSq           , startY + sizeY/2 + cos(angle*deg2rad) * rad4Y - radSq      + sin(useAngle*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad4X + radSq  + cos((useAngle + 90)*deg2rad)*radSq    , startY + sizeY/2 + cos(angle*deg2rad) * rad4Y - radSq      + sin((useAngle + 90)*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad4X + radSq  + cos((useAngle + 180)*deg2rad)*radSq   , startY + sizeY/2 + cos(angle*deg2rad) * rad4Y - radSq      + sin((useAngle + 180)*deg2rad)*radSq);
		glVertex2i(startX+ sizeX/2 + sin(angle*deg2rad) * rad4X + radSq  + cos((useAngle + 270)*deg2rad)*radSq   , startY + sizeY/2 + cos(angle*deg2rad) * rad4Y - radSq      + sin((useAngle + 270)*deg2rad)*radSq);
		glEnd();
	}
	
}
