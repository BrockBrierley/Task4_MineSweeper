#pragma once
#include "button.h"

class mineButton: public button
{
public:
	mineButton();
	void Interact();
	void ArmBomb();
	void SetNearbyMines(int numOfMines);
	int GetNearby();
	void Draw();
protected:
	int nearby = 0;
	bool mine = false;
	void Reveal();
	void Explode();
private:
};

