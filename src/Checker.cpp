#include "Mental_Mystics.h"

void drawCircles(int width, int height);
void drawLines(int startX, int startY, int squareSize, int size);
void drawSquares(int rowNum, double squareSize, int startX, int startY);


void drawSquares(int rowNum, double squareSize, int startX, int startY)
{
	if ((rowNum == 1 || rowNum == 5 || rowNum == 9))
	{
		for(int col = 1; col <=10; col++)
		{
			if(col % 2 == 0)
			{
				glColor3f(1,1,1);
				glRecti(squareSize*(col-1)+startX, squareSize*(rowNum-1)+startY, squareSize*(col)+startX, squareSize*(rowNum)+startY);
			}
			else
			{
				glColor3f(0, 0, 0);
				glRecti(squareSize*(col-1)+startX, squareSize*(rowNum-1)+startY, squareSize*(col)+startX, squareSize*(rowNum)+startY);
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
			glRecti(squareSize*(col-1)+startX+(squareSize/4), squareSize*(rowNum-1)+startY, squareSize*(col)+startX+(squareSize/4), squareSize*(rowNum)+startY);
		}
		else
		{
			glColor3f(0, 0, 0);
			glRecti(squareSize*(col-1)+startX+(squareSize/4), squareSize*(rowNum-1)+startY, squareSize*(col)+startX+(squareSize/4), squareSize*(rowNum)+startY);
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
		glRecti(squareSize*(col-1)+startX+(squareSize/2), squareSize*(rowNum-1)+startY, squareSize*(col)+startX+(squareSize/2), squareSize*(rowNum)+startY);
		}
		else
		{
			glColor3f(0, 0, 0);
			glRecti(squareSize*(col-1)+startX+(squareSize/2), squareSize*(rowNum-1)+startY, squareSize*(col)+startX+(squareSize/2), squareSize*(rowNum)+startY);
		}
	}
}
}
void drawLines(int startX, int startY, int squareSize, int size)
{
	for (int i = 1; i<=10; i++)
	{
		glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex2i(startX, (i-1)*squareSize+startY);
		glVertex2i(size+startX,(i-1)*squareSize+startY);
		glEnd();
	}
}

void drawLineIllusion(int startX, int startY, int size)
{
	double squareSize = (size)*2/19;
	for (int row = 1; row <=10; row++)
	{
		drawSquares(row, squareSize, startX, startY);
		
	}
	drawLines(startX, startY, squareSize, size);
}