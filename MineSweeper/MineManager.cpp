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
		mines[i].SetX((i % xWidth)*buttonSize);
		mines[i].SetY((i / yWidth)*buttonSize);
	}
}                                                                                                                                                                      

void MineManager::DrawMines()
{
	for (int i = 0; i < total; i++)
	{
		mines[i].Draw(buttonImage, pressedImage);
	}
}

void MineManager::PressButton(int index)
{
	mines[index].Interact();
}

void MineManager::RightClick(int index)
{
	mines[index].Flag();
}







