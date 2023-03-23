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
	bool interactable;
	int x;
	int y;
	Vector2 pos;
	Texture2D buttonImage;
	Texture2D pressedImage;
private:
};

