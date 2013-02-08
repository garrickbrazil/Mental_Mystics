/**********************************************************
 * Header: Mental_Mystics.h
 * Purpose: contains all shared header info for project
 *********************************************************/

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 640
#define HEIGHT 480
#define ARROW_W 65
#define ARROW_H 50


typedef enum {MAIN_MENU, ILLUSION_1, ILLUSION_2} STATE;
typedef enum {UP, DOWN, LEFT, RIGHT} DIRECTION;

class GLintPoint{
	
	public: int x; int y;
	
	GLintPoint(int a, int b){
		x=a;
		y=b;
	}
};

// Prototypes
void initialize();
void display();
void keys( unsigned char key, int x, int y );
void keysSpecial(int key, int x, int y);
void drawDiamond(GLintPoint center, int size);
void drawArrow(GLintPoint arrow_tip, DIRECTION direction);
void drawTextTitle(int centerX, int centerY, char* text);
void drawText12(int centerX, int centerY, char* text);
void drawText15(int centerX, int centerY, char* text);
void mouseClick(int button, int buttonState, int x, int y);
void drawLineIllusion(int startX, int startY, int size);
void drawLines(int startX, int startY, int squareSize, int size);
void drawSquares(int rowNum, double squareSize, int startX, int startY);