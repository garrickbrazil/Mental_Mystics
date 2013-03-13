/**********************************************************
 * Garrick Brazil, Edward Cana, Devin Holland, Danny Peterson
 * Computer Graphics
 * Dr. Peter Stanchev
 * Mental Mystics: Main.cpp
 * Description: controls GUI and runs program
 *********************************************************/

#include "Mental_Mystics.h"

// Titles
char TITLE_MAIN[] = "Mental Mystics", TITLE_LINES[] = "Lines & Circles",
	 TITLE_CHECKER[] = "Slanted Checkers", TITLE_BLACKDOTS[] = "Black Dots",
	 TITLE_PEG[] = "Three Pegs", TITLE_SPI[] = "Spiral Squares";

int arrow_padding = 15;
int HEIGHT_IL = HEIGHT * .8;
extern float t;

GLintPoint left_arrow_tip(arrow_padding, HEIGHT - ARROW_H/2 - arrow_padding);
GLintPoint right_arrow_tip(WIDTH - arrow_padding, HEIGHT - ARROW_H/2 - arrow_padding);

int state, mode, first_state, last_state;

/**********************************************************
 * Function: main
 * Purpose: draws a checkerboard using openGL
 *********************************************************/
int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Mental Mystics");
	initialize();
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glutSpecialFunc(keysSpecial);
	glutMouseFunc(mouseClick);
	glutMainLoop();

	return 0;
}

/**********************************************************
 * Function: initialize
 * Purpose: one time initialization (color and ortho size)
 *********************************************************/
void initialize(){
	
	// States
	state = MAIN_MENU;
	last_state = ILLUSION_6;
	
	// Timing
	t = 0;
	Timer(0);
	
	// General
	mode = STATIC;
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}


/**********************************************************
 * Function: keys
 * Purpose: controls keyboard movements
 *********************************************************/
void keys( unsigned char key, int x, int y ) {

	switch( key ) {
		
		// Key combinations
		case 'a': if(state != first_state) state--; break;
		case 'd': if(state != last_state) state++; break;
		case 32: 
				if (mode == STATIC) mode = ANIMATION;
				else{ mode = STATIC; t = 0; }
				display();
				break;
		case 27: exit(1);
		default: break;
	}
	
	display();
}


/**********************************************************
 * Function: keysSpecial
 * Purpose: controls special keyboard movements
 *********************************************************/
void keysSpecial(int key, int x, int y) {

	switch(key) {
		
		// Key combinations
		case GLUT_KEY_LEFT: if(state != first_state) state--; t = 0; mode = STATIC; break;
		case GLUT_KEY_RIGHT: if(state != last_state) state++; t = 0; mode = STATIC; break;
		default: break;
	}
	
	display();
}

/**********************************************************
 * Function: Timer
 * Purpose: sets up clock for program
 *********************************************************/
void Timer(int iUnused){
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}


/**********************************************************
 * Function: mouseClick
 * Purpose: handles button click
 *********************************************************/
void mouseClick(int button, int buttonState, int x, int y){
	
	// Left click
	if ((button == GLUT_LEFT_BUTTON) && (buttonState == GLUT_DOWN)){
		
		// Meet Y criteria
		if(HEIGHT - y < left_arrow_tip.y + ARROW_H/2 && HEIGHT - y > left_arrow_tip.y - ARROW_H/2){
		
			// Left or Right arrow?
			if (state != first_state && x > left_arrow_tip.x && x < left_arrow_tip.x + ARROW_W) state--;
			else if(state != last_state && x < right_arrow_tip.x && x > right_arrow_tip.x - ARROW_W) state++;
			
			display();
		}
	}
}


/**********************************************************
 * Function: display
 * Purpose: display function to call when resize / reload
 *********************************************************/
void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(1);
	
	if (state == MAIN_MENU){	
			
		char inst[] = "Press enter to continue...";	
		char by_Line1[] = "By Garrick Brazil, Devin Holland";
		char by_Line2[] = "Edward Cana, Daniel Peterson";
		
		// Main titles
		drawTextTitle(WIDTH/2, (HEIGHT - arrow_padding)*70/100, TITLE_MAIN);
		drawText12(WIDTH/2, (HEIGHT - arrow_padding)*40/100, by_Line1);
		drawText12(WIDTH/2, (HEIGHT - arrow_padding)*40/100 - 18, by_Line2);
	}
	
	else if(state == ILLUSION_1){
		
		char instLinesCircles[] = "Are the lines equal?";
		
		if(mode == STATIC) drawCircles(WIDTH , (HEIGHT_IL - ARROW_H - arrow_padding));
		else animatedDrawCircles(WIDTH , (HEIGHT_IL - ARROW_H - arrow_padding));
		
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, TITLE_LINES);
		drawText15(WIDTH/2, HEIGHT_IL, instLinesCircles);
		
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		drawArrow(right_arrow_tip, RIGHT);
	}
	
	else if(state == ILLUSION_2){
	
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		drawArrow(right_arrow_tip, RIGHT);
	
		char instLineIl[] = "Are the lines straight..";
		char instLineIl2[] = "or slanted?";
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, TITLE_CHECKER);
		
		drawText15(WIDTH/2, HEIGHT_IL + 15, instLineIl);
		drawText15(WIDTH/2, HEIGHT_IL - 5, instLineIl2);
		
		if(mode == STATIC) drawLineIllusion(WIDTH/2 - (HEIGHT_IL - ARROW_H - arrow_padding)/2, 15, (HEIGHT_IL - ARROW_H - arrow_padding));
		else drawLineIllusionAni(WIDTH/2 - (HEIGHT_IL - ARROW_H - arrow_padding)/2, 15, (HEIGHT_IL - ARROW_H - arrow_padding));
		
		
	}
	
	else if (state == ILLUSION_3){
		
		
		drawDisappearGrad(WIDTH, (HEIGHT_IL - ARROW_H - arrow_padding));
		
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		drawArrow(right_arrow_tip, RIGHT);
	
		char titleDisappear[] = "Vanishing Gradient";
		char instDisappear[] = "Stare at the black dot and";
		char instDisappear2[] = "watch the background disappear.";
		
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, titleDisappear);
		drawText15(WIDTH/2, HEIGHT_IL + 15, instDisappear);
		drawText15(WIDTH/2, HEIGHT_IL - 5, instDisappear2);
		
	}
	
	else if (state == ILLUSION_4){
		
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		drawArrow(right_arrow_tip, RIGHT);
	
		char instBlackDots[] = "Are the dots white..";
		char instBlackDots2[] = "or black?";
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, TITLE_BLACKDOTS);
		drawText15(WIDTH/2, HEIGHT_IL + 15, instBlackDots);
		drawText15(WIDTH/2, HEIGHT_IL - 5, instBlackDots2);
		if(mode == STATIC) drawBlackDots(WIDTH/2 - (HEIGHT_IL - ARROW_H - arrow_padding)/2, 15, (HEIGHT_IL - ARROW_H - arrow_padding));
		else drawBlackDotsAni(WIDTH/2 - (HEIGHT_IL - ARROW_H - arrow_padding)/2, 15, (HEIGHT_IL - ARROW_H - arrow_padding));
	}
	
	else if (state == ILLUSION_5){
		
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		drawArrow(right_arrow_tip, RIGHT);
	
		char instPeg[] = "Look closely..";
		char instPeg2[] = "How is this possible?";
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, TITLE_PEG);
		drawText15(WIDTH/2, HEIGHT_IL + 15, instPeg);
		drawText15(WIDTH/2, HEIGHT_IL - 5, instPeg2);
		drawMissingPeg((ARROW_H + arrow_padding), 15, WIDTH - 2*(ARROW_H + arrow_padding),(HEIGHT_IL*.8));
	}
	
	else if (state == ILLUSION_6){
	
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		//drawArrow(right_arrow_tip, RIGHT);
	
		char instSpi[] = "Are these circles";
		char instSpi2[] = "or a spiral?";
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, TITLE_SPI);
		drawText15(WIDTH/2, HEIGHT_IL + 15, instSpi);
		drawText15(WIDTH/2, HEIGHT_IL - 5, instSpi2);
		drawSquareSpiral((ARROW_H + arrow_padding), 15, (HEIGHT_IL*.85),(HEIGHT_IL*.85));
	}
	glFlush();
}
