#pragma once
#include "raylib.h"
#include "mineButton.h"
#include "Timer.h"

class MineManager
{
public:
	MineManager( int topGap, int difficulty);
	~MineManager();
	void DrawMines();
	void Draw();
	void PressButton(int Index);
	void PressButton(int mouseX, int mouseY);
	void RightClick(int mouseX, int mouseY);
	void ClearNearby(int x, int y);
	void DrawResetImage();
	void CheckResetButtonPress(int x, int y);
	void CheckResetButtonRelease(int x, int y);
	Texture2D GetImage(int number);
	Texture2D GetBasicButton();
	Texture2D GetFlaggedButton();
	Texture2D GetBombedButton();
	void ArmBombs();
protected:
	void SetNearby();
	void Reset();
	Vector2 resetPos;
	int xSize;
	int ySize;
	int total;
	int numOfMines;
	int buttonSize = 64;
	mineButton* mines;
	bool alive = true;
	bool firsClick = true;
	Timer timer;
	void DrawTimer();
	int topGap;

	float imageSizeMultiplyer = 1;

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

	//load reset button textures
	Texture2D ResetImage_Alive_Unpressed;
	Texture2D ResetImage_Alive_Pressed;
	Texture2D ResetImage_Dead_Unpressed;
	Texture2D ResetImage_Dead_Pressed;

	//Stored pointer to the resetImage
	Texture2D* resetImage;

private:
};

