#include "Mental_Mystics.h"

void drawDisappearGrad(int width, int height){

	glClear( GL_COLOR_BUFFER_BIT );		// Clear pixels in buffer
	float i = 1.0f;
	int radius = width/4;
	float incr = (float) ((2 * 3.14159) / 50);
	while(radius >= 1)
	{
	glColor3f(i, i, i);			// Change color to red

	glBegin(GL_TRIANGLE_FAN);
	    glVertex2f((width / 2), (height / 2));
	    for(int x = 0; x < 50; x++)
	    {
	    	float angle = incr * x;

	        float x = (float) cos(angle) *radius;
	        float y = (float) sin(angle) *radius;

	        glVertex2f((width / 2) + x, (height / 2) + y);
	    }
	    glVertex2f((width / 2) + radius, (height / 2));
    glEnd();
    radius = radius - 1;
    i = i - 0.00480;
	}
	glColor3f(0.0, 0.0, 0.0);
	radius = width/100;
	
	glBegin(GL_TRIANGLE_FAN);
	    glVertex2f((width / 2), (height / 2));
	    for(int x = 0; x < 50; x++)
	    {
	    	float angle = incr * x;

	        float x = (float) cos(angle) *radius;
	        float y = (float) sin(angle) *radius;

	        glVertex2f((width / 2) + x, (height / 2) + y);
	    }
	    glVertex2f((width / 2) + radius, (height / 2));
    glEnd();
	
}