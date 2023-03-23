#pragma once
#include "button.h"

class mineButton: public button
{
public:
	mineButton();
	void Interact();
	void Flag();
	void ArmBomb();
	void SetNearbyMines(int numOfMines);
	int GetNearby();
	void SetX(int x);
	void SetY(int y);
	void Draw(Texture2D normal, Texture2D pressed);
protected:
	int nearby = 0;
	bool mine = false;
	void Reveal();
	void Explode();
	int xPos = 0;
	int yPos = 0;
	bool flagged = false;
private:
};

