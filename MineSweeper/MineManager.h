#pragma once
#include "mineButton.h"
class MineManager
{
public:
	MineManager(int xWidth, int yWidth);
	void DrawMines();

	Texture2D GetImage();
protected:
	int xSize;
	int ySize;
	int total;
	int buttonSize = 64;
	mineButton* mines;
	Texture2D buttonImage;
	Texture2D pressedImage;
private:
};

