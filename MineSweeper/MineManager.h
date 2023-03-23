#pragma once
#include "mineButton.h"
class MineManager
{
public:
	MineManager(int xWidth, int yWidth);
	void DrawMines();
	void PressButton(int Index);
	void RightClick(int Index);
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

