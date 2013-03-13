/**********************************************************
 * Header: Mental_Mystics.h
 * Purpose: contains all shared header info for project
 *********************************************************/

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 700
#define HEIGHT 600
#define ARROW_W 65
#define ARROW_H 50


typedef enum {MAIN_MENU, ILLUSION_1, ILLUSION_2, ILLUSION_3, ILLUSION_4, ILLUSION_5, ILLUSION_6} STATE;
typedef enum {UP, DOWN, LEFT, RIGHT} DIRECTION;
typedef enum {ANIMATION, STATIC} MODE;

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
void Timer(int iUnused);

// General
void drawCircle(int x, int y, float radius);
void glEllipse4i(int x, int y, float radiusX, float radiusY);
void glCircle3i(int x, int y, int radius);

// Draw text
void drawTextTitle(int centerX, int centerY, char* text);
void drawText12(int centerX, int centerY, char* text);
void drawText15(int centerX, int centerY, char* text);

// Arrow
void drawArrow(GLintPoint arrow_tip, DIRECTION direction);

// Illusions
void drawLineIllusion(int startX, int startY, int size);
void drawLineIllusionAni(int startX, int startY, int size);
void drawCircles(int width, int height);
void animatedDrawCircles(int width, int height);
void drawBlackDots(int startX, int startY, int size);
void drawBlackDotsAni(int startX, int startY, int size);
void drawDisappearGrad(int width, int height);
void drawMissingPeg(int startX, int startY, int sizeX, int sizeY);
void drawSquareSpiral(int startX, int startY, int sizeX, int sizeY);