#pragma once
#include "button.h"

class mineButton: public button
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

protected:
	int nearby = 0;
	bool mine = false;
	bool revealed = false;
	void Explode();
	bool flagged = false;
	int xArrayPos;
	int yArrayPos;
private:
};

