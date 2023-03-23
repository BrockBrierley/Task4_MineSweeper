#include "mineButton.h"


mineButton::mineButton()
{
	
}

void mineButton::SetX(int x)
{
	pos.x = x*64;
}

void mineButton::SetY(int y)
{
	pos.y = y*64;
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

void mineButton::SetManager(MineManager* mineMan)
{
	this->mineMan = mineMan;
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


void mineButton::Draw(Texture2D normal)
{
	DrawTextureEx(normal, pos, 0.0f, 0.5f, WHITE);
}