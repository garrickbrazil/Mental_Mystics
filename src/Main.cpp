/**********************************************************
 * Garrick Brazil, Edward Cana, Devin Holland, Danny Peterson
 * Computer Graphics
 * Dr. Peter Stanchev
 * Mental Mystics: Main.cpp
 * Description: controls GUI and runs program
 *********************************************************/

#include "Mental_Mystics.h"

char TITLE_MAIN[] = "Mental Mystics";
char TITLE_LINES[] = "Lines & Circles";
char TITLE_CHECKER[] = "Slanted Checkers";
char TITLE_BLACKDOTS[] = "Black Dots";
int arrow_padding = 15;

GLintPoint left_arrow_tip(arrow_padding, HEIGHT - ARROW_H/2 - arrow_padding);
GLintPoint right_arrow_tip(WIDTH - arrow_padding, HEIGHT - ARROW_H/2 - arrow_padding);

int state;
int first_state = MAIN_MENU;
int last_state = ILLUSION_3;

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
 * Function: keys
 * Purpose: controls keyboard movements
 *********************************************************/
void keys( unsigned char key, int x, int y ) {

	switch( key ) {
		
		// Key combinations
		case 'a': if(state != first_state) state--; break;
		case 'd': if(state != last_state) state++; break;
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
		case GLUT_KEY_LEFT: if(state != first_state) state--; break;
		case GLUT_KEY_RIGHT: if(state != last_state) state++; break;
		default: break;
	}
	
	display();
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
 * Function: initialize
 * Purpose: one time initialization (color and ortho size)
 *********************************************************/
void initialize(){

	state = MAIN_MENU;
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}


/**********************************************************
 * Function: display
 * Purpose: display function to call when resize / reload
 *********************************************************/
void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
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
			
		
		
		drawCircles(WIDTH , (HEIGHT - ARROW_H - arrow_padding*3));
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, TITLE_LINES);
		
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		drawArrow(right_arrow_tip, RIGHT);
	}
	
	else if(state == ILLUSION_2){
	
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		drawArrow(right_arrow_tip, RIGHT);
	
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, TITLE_CHECKER);
		drawLineIllusion(WIDTH/2 - (HEIGHT - ARROW_H - arrow_padding*3)/2, 15, (HEIGHT - ARROW_H - arrow_padding*3));
		
	}
	
	else if (state == ILLUSION_3){
		
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		//drawArrow(right_arrow_tip, RIGHT);
	
		drawTextTitle(WIDTH/2, HEIGHT - arrow_padding - 24, TITLE_BLACKDOTS);
		drawBlackDots(WIDTH/2 - (HEIGHT - ARROW_H - arrow_padding*3)/2, 15, (HEIGHT - ARROW_H - arrow_padding*3));
	}
	
	glFlush();
}
