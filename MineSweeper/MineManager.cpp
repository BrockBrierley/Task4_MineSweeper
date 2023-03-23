#include "MineManager.h"

MineManager::MineManager(int xWidth, int yWidth)
{
	buttonImage = LoadTexture("ArtAssets/Unknown_Unpressed_Button.png");
	pressedImage = LoadTexture("ArtAssets/Unknown_Pressed_Button.png");

	xSize = xWidth;
	ySize = yWidth;
	total = xSize * ySize;

	mines = new mineButton[total];

	for (int i = 0; i < total; i++)
	{
		mines[i].SetX(i % xWidth);
		mines[i].SetY(i / yWidth);
		//mines[i].SetManager(this);
	}
}

void MineManager::DrawMines()
{
	for (int i = 0; i < total; i++)
	{
		if (i % 4 == 0)
		{
			mines[i].Draw(pressedImage);
		}
		else
		{
			mines[i].Draw(buttonImage);
		}
	}
}







