#pragma once
#include "raylib.h"
#include "mineButton.h"

class MineManager
{
public:
	MineManager(int xWidth, int yWidth);
	void DrawMines();
	void PressButton(int Index);
	void RightClick(int Index);
	void ClearNearby(int x, int y);
	Texture2D GetImage(int number);
	Texture2D GetBasicButton();
	Texture2D GetFlaggedButton();
	Texture2D GetBombedButton();
protected:
	void SetNearby();
	int xSize;
	int ySize;
	int total;
	int numOfMines;
	int buttonSize = 64;
	mineButton* mines;
	bool alive = true;
	bool firsClick = true;

	//textures to load in manager, so they are not loaded for every mine
	Texture2D buttonImage;
	Texture2D FlaggedImage;
	Texture2D BombedImage;

	//Number Images
	Texture2D EmptyImage;
	Texture2D OneImage;
	Texture2D TwoImage;
	Texture2D ThreeImage;
	Texture2D FourImage;
	Texture2D FiveImage;
	Texture2D SixImage;
	Texture2D SevenImage;
	Texture2D EightImage;

private:
};

