#include "Mental_Mystics.h"

/**********************************************************
 * Function: drawArrow
 * Purpose: draws an arrow with a direction and position
 *********************************************************/
void drawArrow(GLintPoint arrow_tip, DIRECTION direction){
	
	glColor3f(0.0f, 0.0f, 0.0f);
	
	if(direction == LEFT){
	
		// Draw arrow facing left
		glBegin(GL_LINE_LOOP);
		glVertex2i(arrow_tip.x, arrow_tip.y);
		glVertex2i(arrow_tip.x + ARROW_W * 42/100, arrow_tip.y + ARROW_H * 50/100);
		glVertex2i(arrow_tip.x + ARROW_W * 42/100, arrow_tip.y + ARROW_H * 18/100);
		glVertex2i(arrow_tip.x + ARROW_W, arrow_tip.y + ARROW_H * 18/100);
		glVertex2i(arrow_tip.x + ARROW_W, arrow_tip.y - ARROW_H * 18/100);
		glVertex2i(arrow_tip.x + ARROW_W * 42/100, arrow_tip.y - ARROW_H * 18/100);
		glVertex2i(arrow_tip.x + ARROW_W * 42/100, arrow_tip.y - ARROW_H * 50/100);
		glEnd();
	}
	
	else if (direction == RIGHT){
	
		// Draw arrow facing right
		glBegin(GL_LINE_LOOP);
		glVertex2i(arrow_tip.x, arrow_tip.y);
		glVertex2i(arrow_tip.x - ARROW_W * 42/100, arrow_tip.y + ARROW_H * 50/100);
		glVertex2i(arrow_tip.x - ARROW_W * 42/100, arrow_tip.y + ARROW_H * 18/100);
		glVertex2i(arrow_tip.x - ARROW_W, arrow_tip.y + ARROW_H * 18/100);
		glVertex2i(arrow_tip.x - ARROW_W, arrow_tip.y - ARROW_H * 18/100);
		glVertex2i(arrow_tip.x - ARROW_W * 42/100, arrow_tip.y - ARROW_H * 18/100);
		glVertex2i(arrow_tip.x - ARROW_W * 42/100, arrow_tip.y - ARROW_H * 50/100);
		glEnd();
	}
}