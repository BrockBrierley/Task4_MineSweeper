#include "mineButton.h"
#include "MineManager.h"

mineButton::mineButton()
{
	
}

mineButton::~mineButton()
{
}

void mineButton::SetX(int xPos, int x)
{
	pos.x = xPos;
	xArrayPos = x;
}

void mineButton::SetY(int yPos, int y)
{
	pos.y = yPos;
	yArrayPos = y;
}


void mineButton::ArmBomb()
{
	mine = true;
}

void mineButton::DisarmBomb()
{
	mine = false;
}

void mineButton::SetNearbyMines(int numOfMines)
{
	nearby = numOfMines;
}

int mineButton::GetNearby()
{
	return nearby;
}

void mineButton::Flag()
{
	if (flagged)
	{
		flagged = false;
		interactable = true;
	}
	else if (!flagged && interactable)
	{
		flagged = true;
		interactable = false;
	}
}

void mineButton::Interact(MineManager* manager)
{
	if (interactable)
	{
		interactable = false;
		revealed = true;

		if (mine)
		{
			Explode();
		}
		else
		{
			if (nearby == 0)
			{
				manager->ClearNearby(xArrayPos, yArrayPos);
			}
		}
	}
}

void mineButton::Explode() 
{
	//Play Sound
}

void mineButton::Draw(MineManager* manager, float imageSizeMultiplyer)
{
	if (mine && revealed)
	{
		DrawTextureEx(manager->GetBombedButton(), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	else if (flagged)
	{
		DrawTextureEx(manager->GetFlaggedButton(), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	else if (revealed)
	{
		DrawTextureEx(manager->GetImage(nearby), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	else
	{
		DrawTextureEx(manager->GetBasicButton(), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
}

bool mineButton::IsMine()
{
	return mine;
}

bool mineButton::IsFlagged()
{
	return flagged;
}

void mineButton::Reset()
{
	mine = false;
	flagged = false;
	nearby = 0;
	interactable = true;
	revealed = false;
}
