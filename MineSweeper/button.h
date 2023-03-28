#pragma once
#include "raylib.h"

class button
{
public:
	button();
	void Interact();
	void SetPosition(int newX, int newY);
	int GetXPos();
	int GetYPos();
protected:
	int counter;
	int buttonWidth = 64;
	bool interactable = true;
	Vector2 pos;
private:
};


