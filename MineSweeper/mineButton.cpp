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

int mineButton::Flag()
{
	if (flagged)
	{
		flagged = false;
		interactable = true;
		return 0;
	}
	else if (!flagged && interactable)
	{
		flagged = true;
		interactable = false;
		return 1;
	}
	else
	{
		return -1;
	}
}

bool mineButton::Interact(MineManager* manager)
{
	if (interactable)
	{
		interactable = false;
		revealed = true;

		if (mine)
		{
			return false;
		}
		else
		{
			if (nearby == 0)
			{
				manager->ClearNearby(xArrayPos, yArrayPos);
			}
			return true;
		}
	}
}

void mineButton::Draw(MineManager* manager, float imageSizeMultiplyer)
{
	int normal = 0;
	int flag = 1;
	int bomb = 2;
	if (mine && revealed && clickedSquare)
	{
		DrawTextureEx(imageManager->GetBasicButton(bomb), pos, 0.0f, imageSizeMultiplyer, RED);
	}
	else if (mine && revealed)
	{
		DrawTextureEx(imageManager->GetBasicButton(bomb), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	else if (flagged && mine && !manager->IsAlive())
	{
		DrawTextureEx(imageManager->GetBasicButton(flag), pos, 0.0f, imageSizeMultiplyer, GREEN);
	}
	else if (flagged)
	{
		DrawTextureEx(imageManager->GetBasicButton(flag), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	else if (revealed)
	{
		DrawTextureEx(imageManager->GetNumberedButton(nearby), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	else
	{
		DrawTextureEx(imageManager->GetBasicButton(normal), pos, 0.0f, imageSizeMultiplyer, WHITE);
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
	clickedSquare = false;
}

void mineButton::SetImageManager(ImageManager* im)
{
	imageManager = im;
}

