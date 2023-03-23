#pragma once
#include "button.h"
#include "MineManager.h"

class mineButton: public button
{
public:
	mineButton();
	void Interact();
	void ArmBomb();
	void SetNearbyMines(int numOfMines);
	int GetNearby();
	void SetX(int x);
	void SetY(int y);
	void Draw(Texture2D d);
	void SetManager(MineManager* mineMan);
protected:
	int nearby = 0;
	bool mine = false;
	void Reveal();
	void Explode();
	int xPos = 0;
	int yPos = 0;
	MineManager* mineMan;
private:
};

