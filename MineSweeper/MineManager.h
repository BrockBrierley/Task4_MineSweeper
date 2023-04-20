#pragma once
#include "raylib.h"
#include "mineButton.h"
#include "Timer.h"
#include "SoundManager.h"
#include "ImageManager.h"

class MineManager
{
public:
	MineManager( int topGap, int difficulty, SoundManager* sm, ImageManager* im);
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
	void ArmBombs();
	void ShowAllMines();
	bool IsAlive();
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
	void DrawFlagCounter();
	int topGap;

	int winCount = -1;
	int winCounter = 0;
	int flagCounter = 0;

	float imageSizeMultiplyer = 1;

	SoundManager* soundManager;
	ImageManager* imageManager;

	//Stored pointer to the resetImage
	Texture2D resetImage;

private:
};

