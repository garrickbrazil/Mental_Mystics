#include "Mental_Mystics.h"

extern float t;

/**********************************************************
 * Function: drawBlackDots
 * Purpose: draws black dots illusion
 *********************************************************/
void drawBlackDots(int startX, int startY, int size){

	int gridSize = 7;
	int borderSize = size/(gridSize * 5 + gridSize - 1);
	int squareSize = borderSize*5;
	int rc_size = borderSize + squareSize; 

	int row, col; 
	
	// Grey background
	glColor3f(0.55f, 0.55f, 0.55f);
	glRecti(startX, startY, startX + rc_size*gridSize - borderSize, startY + rc_size*gridSize - borderSize);
	
	for(row = 0; row < gridSize; row++){

		for(col = 0; col < gridSize; col++){
			
			// Square
			glColor3f(0.0f, 0.0f, 0.0f);
			glRecti(rc_size*(col) + startX, rc_size*(row) + startY, rc_size*(col) + startX + squareSize, rc_size*(row) + startY + squareSize);
			
			if(row + 1 < gridSize && col + 1 < gridSize){ 
				
				// Dot
				glColor3f(1.0f, 1.0f, 1.0f);
				glCircle3i(rc_size*(col + 1) + startX - borderSize*.8/2, rc_size*(row+1) + startY - borderSize*.8/2, borderSize*.8);
			}
		}
	}
}

/**********************************************************
 * Function: drawBlackDotsAni
 * Purpose: draws black dots illusion
 *********************************************************/
void drawBlackDotsAni(int startX, int startY, int size){

	int gridSize = 7;
	int borderSize = size/(gridSize * 5 + gridSize - 1);
	int squareSize = borderSize*5;
	int rc_size = borderSize + squareSize; 

	int row, col; 
	
	// Grey background
	glColor3f(0.5f , 0.5f, 0.5f);
	glRecti(startX, startY, startX + rc_size*gridSize - borderSize, startY + rc_size*gridSize - borderSize);
	
	do{
	
		for(row = 0; row < gridSize; row++){

			for(col = 0; col < gridSize; col++){
				
				// Square
				glColor3f(0.0f + .5*t, 0.0f + .5*t, 0.0f + .5*t);
				glRecti(rc_size*(col) + startX, rc_size*(row) + startY, rc_size*(col) + startX + squareSize, rc_size*(row) + startY + squareSize);
				
				if(row + 1 < gridSize && col + 1 < gridSize){ 
					
					// Dot
					glColor3f(1.0f, 1.0f, 1.0f);
					glCircle3i(rc_size*(col + 1) + startX - borderSize*.8/2, rc_size*(row+1) + startY - borderSize*.8/2, borderSize*.8);
				}
			}
		}
		
		glFlush();
		if (t < 1) t += .005;
	}
	while(t < 1);

}