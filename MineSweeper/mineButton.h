#pragma once
#include "raylib.h"

class mineButton
{
public:
	mineButton();
	void Interact(class MineManager* manager);
	void Flag();
	void ArmBomb();
	void DisarmBomb();
	void SetNearbyMines(int numOfMines);
	int GetNearby();
	void SetX(int xPos, int x);
	void SetY(int yPos, int y);
	void Draw(class MineManager* manager);
	bool IsMine();
	bool IsFlagged();
	void Reset();

protected:
	int nearby = 0;
	bool mine = false;
	bool revealed = false;
	void Explode();
	bool interactable = true;
	bool flagged = false;
	int xArrayPos = 0;
	int yArrayPos = 0;
	Vector2 pos;
private:
};

