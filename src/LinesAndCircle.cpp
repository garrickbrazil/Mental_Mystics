#include "Mental_Mystics.h"

void drawCircles(int width, int height)
{
	glClear( GL_COLOR_BUFFER_BIT );		// Clear pixels in buffer
	glColor3f( 0.0, 0.0, 0.0 );			// Change color to red

	float theta = 2 * 3.1415926 / float(30);
	float tangetial_factor = tan(theta);//calculate the tangential factor
	float radial_factor = cos(theta);//calculate the radial factor
	float x = 1;//we start at angle = 0
	float y = 0;
	glBegin(GL_LINE_LOOP);
	for (int angle = 0; angle < 360; angle ++)
	{
		glVertex2f((width / 5) + sin(angle) * (height/10), (2 * height / 3) + cos(angle) * (height/10));
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int angle = 0; angle < 360; angle ++)
	{
		glVertex2f((4 * width / 5) + sin(angle) * (height/10), (2 * height / 3) + cos(angle) * (height/10));
	}
	glEnd();
	glBegin(GL_LINES);
		glVertex2f((width/5) + (height/10), (2 * height /3));
		glVertex2f((4 * width / 5) - (height /10), (2 * height / 3));
	glEnd();

	glBegin(GL_LINE_LOOP);
		for (int angle = 0; angle < 360; angle ++)
		{
			glVertex2f((width / 5) + sin(angle) * (height/10) + (height / 5), (height / 3) + cos(angle) * (height/10));
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (int angle = 0; angle < 360; angle ++)
		{
			glVertex2f((4 * width / 5) + sin(angle) * (height/10)-(height / 5), (height / 3) + cos(angle) * (height/10));
		}
		glEnd();
		glBegin(GL_LINES);
			glVertex2f((width/5) + (height/10), (height /3));
			glVertex2f((4 * width / 5) - (height /10), (height / 3));
		glEnd();
	glFlush();
}