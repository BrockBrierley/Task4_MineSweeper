#include "MineManager.h"
#include <iostream>

MineManager::MineManager(int xWidth, int yWidth)
{
	button resetButton;


	numOfMines = 40;
	//load Basic Images
	buttonImage = LoadTexture("ArtAssets/Unknown_Unpressed_Button.png");
	FlaggedImage = LoadTexture("ArtAssets/Flagged_Button.png");
	BombedImage = LoadTexture("ArtAssets/Bomb_Button.png");

	//Load Number Images
	EmptyImage = LoadTexture("ArtAssets/Empty_Pressed_Button.png");
	OneImage = LoadTexture("ArtAssets/1_Button.png");
	TwoImage = LoadTexture("ArtAssets/2_Button.png");
	ThreeImage = LoadTexture("ArtAssets/3_Button.png");
	FourImage = LoadTexture("ArtAssets/4_Button.png");
	FiveImage = LoadTexture("ArtAssets/5_Button.png");
	SixImage = LoadTexture("ArtAssets/6_Button.png");
	SevenImage = LoadTexture("ArtAssets/7_Button.png");
	EightImage = LoadTexture("ArtAssets/8_Button.png");

	xSize = xWidth;
	ySize = yWidth;
	total = xWidth * yWidth;

	mines = new mineButton[total];

	for (int i = 0; i < total; i++)
	{
		mines[i].SetX( ((i % xWidth)*buttonSize), i % xSize);
		mines[i].SetY( ((i / xWidth)*buttonSize) + 2 * buttonSize, i / xSize);
	}
	//srand(time(nullptr));
	for (int i = 0; i < numOfMines; i++)
	{
		//get a random number between 0 and the total, excluding the total
		//minus 1 before the % and plus 1 after the to ensure mines are not places in the 0 slot which is the failsafe
		//point if the user clicks on a mine
		int randomNum = (rand() % (total - 1)) + 1;
		//rerun if the position already contains a mine
		while (mines[randomNum].IsMine())
		{
			randomNum = (rand() % (total - 1)) + 1;
		}
		mines[randomNum].ArmBomb();
	}
	SetNearby();
}    

void MineManager::SetNearby()
{
	//For Loop GALORE
	for (int y = 0; y < ySize; y++)
	{
		for (int x = 0; x < xSize; x++)
		{
			int counter = 0;
			int startingY;
			int startingX;
			int endingY;
			int endingX;

			//calcuate the start point and end point for each axis to check nearby mines
			//y
			if (y == 0)
			{
				startingY = 0;
			}
			else
			{
				startingY = -1;
			}

			if (y == ySize-1)
			{
				endingY = 0;
			}
			else
			{
				endingY = 1;
			}
			//x
			if (x == 0)
			{
				startingX = 0;
			}
			else
			{
				startingX = -1;
			}

			if (x == xSize - 1)
			{
				endingX = 0;
			}
			else
			{
				endingX = 1;
			}

			//for loop to count nearby mines
			for (int yNearby = startingY; yNearby <= endingY; yNearby++)
			{
				for (int xNearby = startingX; xNearby <= endingX; xNearby++)
				{
					int index = ((y + yNearby) * xSize) + (x + xNearby);
					if (mines[index].IsMine())
					{
						counter++;
					}
				}
			}

			int index = (y * xSize) + x;
			mines[index].SetNearbyMines(counter);
		}
	}
}

void MineManager::ClearNearby(int x, int y)
{
	int startingY;
	int startingX;
	int endingY;
	int endingX;

	//calcuate the start point and end point for each axis to check nearby mines
	//y
	if (y == 0)
	{
		startingY = 0;
	}
	else
	{
		startingY = -1;
	}

	if (y == ySize - 1)
	{
		endingY = 0;
	}
	else
	{
		endingY = 1;
	}
	//x
	if (x == 0)
	{
		startingX = 0;
	}
	else
	{
		startingX = -1;
	}

	if (x == xSize - 1)
	{
		endingX = 0;
	}
	else
	{
		endingX = 1;
	}

	//for loop to count nearby mines
	for (int yNearby = startingY; yNearby <= endingY; yNearby++)
	{
		for (int xNearby = startingX; xNearby <= endingX; xNearby++)
		{
			int index = ((y + yNearby) * xSize) + (x + xNearby);
			mines[index].Interact(this);
		}
	}
}


void MineManager::DrawMines()
{
	for (int i = 0; i < total; i++)
	{
		mines[i].Draw(this);
	}
}

void MineManager::PressButton(int index)
{
	if (index >= 0 && index < total && alive)
	{
		if (mines[index].IsMine() && firsClick)
		{
			mines[index].DisarmBomb();
			mines[0].ArmBomb();
			SetNearby();
		}
		else if(mines[index].IsMine() && !mines[index].IsFlagged())
		{
			alive = false;
		}
		firsClick = false;
		mines[index].Interact(this);
	}
}

void MineManager::RightClick(int index)
{
	if (index >= 0 && index < total && alive)
	{
		mines[index].Flag();
	}
}

Texture2D MineManager::GetImage(int number)
{
	switch (number)
	{
	case 0:
		return EmptyImage;
	case 1:
		return OneImage;
	case 2:
		return TwoImage;
	case 3:
		return ThreeImage;
	case 4:
		return FourImage;
	case 5:
		return FiveImage;
	case 6:
		return SixImage;
	case 7:
		return SevenImage;
	case 8:
		return EightImage;
	default:
		break;
	}
	return buttonImage;
}

Texture2D MineManager::GetBasicButton()
{
	return buttonImage;
}

Texture2D MineManager::GetFlaggedButton()
{
	return FlaggedImage;
}

Texture2D MineManager::GetBombedButton()
{
	return BombedImage;
}








