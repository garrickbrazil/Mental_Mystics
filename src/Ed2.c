/*
 * teapot_main.cpp
 *
 *  Created on: Feb 26, 2013
 *      Author: Ed
 */

#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>

unsigned char direction;
double zoom = -20;
int screenWidth = 640;
int screenHeight = 480;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< displayWire >>>>>>>>>>>>>>>>>>>>>>
void displayWire(void)
{
glMatrixMode(GL_PROJECTION); // set the view volume shape
glLoadIdentity();
glOrtho(-1.5, 1.0, -2.0, 0.5, 0.1, 100);
glMatrixMode(GL_MODELVIEW); // position and aim the camera
glLoadIdentity();
gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, -100.0, 100.0);
glClear(GL_COLOR_BUFFER_BIT); // clear the screen
glColor3d(0,0,0); // draw black lines
glPopMatrix();

glPushMatrix();
glTranslated(0.0,0,0); // cone at (0,0,0)
glutWireCone(0.2, 0.5, 10, 8);
glTranslated(1.0,0,zoom); // cone at (1,0,movement)
glutWireCone(0.2, 0.5, 10, 8);
glPopMatrix();
glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
	//Press keys on keyboard to move shape
		if (key == 'w' || key == 'W')
		{
			direction = 'u';     //moves up
		}
		else if(key =='s' || key == 'S')
		{
			direction = 'd';     //moves down
		}
}

void myMovement()
{
	//moves the camera
		if (direction == 'u')
		{
			zoom = zoom + 0.1;
			direction ='q';
		}
		else if(direction == 'd')
		{
			zoom = zoom - 0.1;
			direction ='q';
		}
		glutPostRedisplay();
}

//Animation for Cube
void update(int value) {
	zoom += 0.1;
	if (zoom > 10) {
		zoom = 10;
	}
	glutPostRedisplay();
	glutTimerFunc(250, update, 0);
}

//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize(640,480);
glutInitWindowPosition(0,0);
glutCreateWindow("Wireframe movement");
glutDisplayFunc(displayWire);
glClearColor(1.0f, 1.0f, 1.0f,0.0f); // background is white
glViewport(0, 0, screenWidth, screenHeight);
glutKeyboardFunc(myKeyboard);     //keys
glutIdleFunc(myMovement);    //continually checks key pressed
glutTimerFunc(250, update, 0);
glutMainLoop();
}

