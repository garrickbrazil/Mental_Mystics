/**********************************************************
 * Header: Mental_Mystics.h
 * Purpose: contains all shared header info for project
 *********************************************************/

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 600
#define ARROW_W 65
#define ARROW_H 50


typedef enum {MAIN_MENU, ILLUSION_1, ILLUSION_2, ILLUSION_3} STATE;
typedef enum {UP, DOWN, LEFT, RIGHT} DIRECTION;

class GLintPoint{
	
	public: int x; int y;
	
	GLintPoint(int a, int b){
		x=a;
		y=b;
	}
};

// Setup
void initialize();
void display();
void keys( unsigned char key, int x, int y );
void keysSpecial(int key, int x, int y);
void mouseClick(int button, int buttonState, int x, int y);

// General
void drawCircle(int x, int y, float radius);
void glCircle3i(int x, int y, int radius);

// Draw text
void drawTextTitle(int centerX, int centerY, char* text);
void drawText12(int centerX, int centerY, char* text);
void drawText15(int centerX, int centerY, char* text);

// Arrow
void drawArrow(GLintPoint arrow_tip, DIRECTION direction);

// Illusions
void drawLineIllusion(int startX, int startY, int size);
void drawCircles(int width, int height);
void drawBlackDots(int startX, int startY, int size);