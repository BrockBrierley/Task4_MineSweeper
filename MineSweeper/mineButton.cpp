#include "mineButton.h"


mineButton::mineButton()
{
	
}

void mineButton::SetX(int x)
{
	pos.x = x;
}

void mineButton::SetY(int y)
{
	pos.y = y;
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

void mineButton::Interact()
{
	if (interactable)
	{
		interactable = false;
	}
}

void mineButton::Flag()
{
	if (flagged)
	{
		flagged = false;
		interactable = true;
	}
	else if (!flagged && !interactable)
	{

	}
	else
	{
		flagged = true;
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


void mineButton::Draw(Texture2D normal, Texture2D pressed )
{
	if (flagged)
	{
		DrawTextureEx(pressed, pos, 0.0f, 0.5f, WHITE);
	}
	else if (interactable)
	{
		DrawTextureEx(normal, pos, 0.0f, 0.5f, WHITE);
	}
	else
	{
		DrawTextureEx(pressed, pos, 0.0f, 0.5f, WHITE);
	}
}