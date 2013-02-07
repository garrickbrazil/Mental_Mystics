/**********************************************************
 * Garrick Brazil, Edward Cana, Devin Holland, Danny Peterson
 * Computer Graphics
 * Dr. Peter Stanchev
 * Mental Mystics: Main.cpp
 * Description: controls GUI and runs program
 *********************************************************/

#include "Mental_Mystics.h"

int state;

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
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	initialize();
	glutMainLoop();

	return 0;
}

/**********************************************************
 * Function: keyboard
 * Purpose: controls keyboard movements
 *********************************************************/
void keyboard( unsigned char key, int x, int y ) {

	switch( key ) {
		
		// Key combinations
		case 'a': if(state != MAIN_MENU) state--; break;
		case 'd': if(state != ILLUSION_1) state++; break;
		default: break;
	}
	
	display();
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
		
		int arrow_padding = 15;
		
		// Set arrow cordinates
		GLintPoint left_arrow_tip(arrow_padding, HEIGHT - ARROW_H/2 - arrow_padding);
		GLintPoint right_arrow_tip(WIDTH - arrow_padding, HEIGHT - ARROW_H/2 - arrow_padding);
		
		// Draw arrows
		drawArrow(left_arrow_tip, LEFT);
		drawArrow(right_arrow_tip, RIGHT);
	}
	
	else{
	
		// Centers
		GLintPoint d1_center(200, 200);
		GLintPoint d2_center(320, 215);
		GLintPoint d3_center(460, 315);
		GLintPoint d4_center(500, 100);
		GLintPoint d5_center(320, 415);
		GLintPoint d6_center(120, 250);
		
		// Draw
		drawDiamond(d1_center, 28);
		drawDiamond(d2_center, 50);
		drawDiamond(d3_center, 35);
		drawDiamond(d4_center, 20);
		drawDiamond(d5_center, 40);
		drawDiamond(d6_center, 60);
	}
	
	glFlush();
}
