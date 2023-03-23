#include "mineButton.h"


mineButton::mineButton()
{
	this->x = 10;
	this->y = 10;
	pos.x = x;
	pos.y = y;
	counter = 0;
	buttonImage = LoadTexture("ArtAssets/Unknown_Unpressed_Button.png");
	pressedImage = LoadTexture("ArtAssets/Unknown_Pressed_Button.png");
}



void mineButton::ArmBomb()
{
	mine = true;
}

void mineButton::SetNearbyMines(int numOfMines)
{
	nearby = numOfMines;
}

int mineButton::GetNearby()
{
	return nearby;
}

void mineButton::Draw()
{
	counter++;
	if (counter < 60)
	{
		DrawTextureEx(buttonImage, pos,0.0f, 0.5f, WHITE);
	}
	else if (counter >= 70)
	{
		counter = 0;
	}
	else
	{
		DrawTextureEx(pressedImage, pos, 0.0f, 0.5f, WHITE);
	}
}


void mineButton::Interact()
{
	if (interactable)
	{
		interactable = false;

	}
}

void mineButton::Reveal()
{
	if (mine)
	{
		Explode();
		//mineManager.Explode(x, y);
	}
	else
	{
		//ShowNumber
	}
}

void mineButton::Explode()
{
	//destroy all other mines
}