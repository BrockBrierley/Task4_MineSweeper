#include "button.h"

button::button()
{
	interactable = true;
	this->x = 0;
	this->y = 0;
}

void button::Interact()
{
	//figure out this, may need to create a new class for each individual button
	//most likely
}

void button::SetPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}

int button::GetXPos()
{
	return x;
}

int button::GetYPos()
{
	return y;
}
