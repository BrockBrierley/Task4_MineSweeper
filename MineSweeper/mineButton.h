#pragma once
#include "raylib.h"
#include "ImageManager.h"

class mineButton
{
public:
	mineButton();
	~mineButton();
	bool Interact(class MineManager* manager);
	int Flag();
	void ArmBomb();
	void DisarmBomb();
	void SetNearbyMines(int numOfMines);
	int GetNearby();
	void SetX(int xPos, int x);
	void SetY(int yPos, int y);
	void Draw(class MineManager* manager, float imageSizeMultiplyer);
	bool IsMine();
	bool IsFlagged();
	void Reset();
	bool clickedSquare = false;

	void SetImageManager(ImageManager* im);

protected:
	int nearby = 0;
	bool mine = false;
	bool revealed = false;
	bool interactable = true;
	bool flagged = false;
	int xArrayPos = 0;
	int yArrayPos = 0;
	Vector2 pos;
private:
	ImageManager* imageManager;
};

