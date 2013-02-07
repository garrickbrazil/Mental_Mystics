
/*
* dino.cpp
*
* Created on: Jan 20, 2013
* Author: Devin Holland
*/
#include <GL/glut.h>
#include <stdlib.h>
const int screenWidth = 1024;
const int screenHeight = 800;
void myInit(void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
glColor3f (0.0f, 0.0f, 0.0f);
glPointSize (4.0);
glMatrixMode (GL_PROJECTION);
glLoadIdentity();
gluOrtho2D (0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}
void drawSquares(int rowNum)
{
if ((rowNum == 1 || rowNum == 5 || rowNum == 9))
{
for(int col = 1; col <=10; col++)
{
if(col % 2 == 0)
{
glColor3f(1,1,1);
glRecti(50*(col), 50*(rowNum), 50*(col+1), 50*(rowNum+1));
}
else
{
glColor3f(0, 0, 0);
glRecti(50*(col), 50*(rowNum), 50*(col+1), 50*(rowNum+1));
}
}
}
else if ((rowNum ==2) || (rowNum == 4) || (rowNum == 8) || (rowNum == 6))
{
for(int col = 1; col <=10; col++)
{
if(col % 2 == 0)
{
glColor3f(1,1,1);
glRecti(50*(col)+12, 50*(rowNum), 50*(col+1)+12, 50*(rowNum+1));
}
else
{
glColor3f(0, 0, 0);
glRecti(50*(col)+12, 50*(rowNum), 50*(col+1)+12, 50*(rowNum+1));
}
}
}
else if(rowNum == 3 || rowNum == 7)
{
for(int col = 1; col <=10; col++)
{
if(col % 2 == 0)
{
glColor3f(1,1,1);
glRecti(50*(col)+24, 50*(rowNum), 50*(col+1)+24, 50*(rowNum+1));
}
else
{
glColor3f(0, 0, 0);
glRecti(50*(col)+24, 50*(rowNum), 50*(col+1)+24, 50*(rowNum+1));
}
}
}
glFlush();
}
void drawLines()
{
for (int i = 1; i<=10; i++)
{
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2i(50,i*50);
glVertex2i(525,i*50);
glEnd();
}
glFlush();
}
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
for (int row = 1; row <=10; row++)
{
drawSquares(row);
glEnd();
}
drawLines();
}
int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Line Illusion");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
