#include "MineManager.h"
#include <iostream>

MineManager::MineManager(int gap, int difficulty)
{
	topGap = gap;
	//set the number of mines
	if (difficulty == 0)
	{
		numOfMines = 3;
		xSize = 8;
		ySize = 7;
		buttonSize *= 2;
		imageSizeMultiplyer = 2;
	}
	else if (difficulty == 1)
	{
		numOfMines = 30;
		xSize = 16;
		ySize = 14;
		imageSizeMultiplyer = 1;
	}
	else if (difficulty == 2)
	{
		numOfMines = 60;
		xSize = 32;
		ySize = 28;
		buttonSize /= 2;
		imageSizeMultiplyer = 0.5f;
	}
	//default if there is an unchecked number input
	else
	{
		numOfMines = 30;
		xSize = 16;
		ySize = 14;
	}

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

	//LoadResetButton Images

	ResetImage_Alive_Unpressed = LoadTexture("ArtAssets/HappyUnpressed.png");;
	ResetImage_Alive_Pressed = LoadTexture("ArtAssets/HappyPressed.png");;
	ResetImage_Dead_Unpressed = LoadTexture("ArtAssets/DeadUnpressed.png");;
	ResetImage_Dead_Pressed = LoadTexture("ArtAssets/DeadPressed.png");;

	resetImage = &ResetImage_Alive_Unpressed;
	resetPos.x = ((1024 / 2) - 32);
	resetPos.y = 10;

	total = xSize * ySize;

	winCount = total - numOfMines;
	flagCounter = numOfMines;

	mines = new mineButton[total];

	for (int i = 0; i < total; i++)
	{
		mines[i].SetX( ((i % xSize)*buttonSize), i % xSize);
		mines[i].SetY( ((i / xSize)*buttonSize) + topGap, i / xSize);
	}


	ArmBombs();
	SetNearby();
}    


void MineManager::DrawResetImage()
{
	DrawTextureEx((*resetImage), resetPos, 0.0f, 1.0f, WHITE);
}

void MineManager::CheckResetButtonPress(int x, int y)
{
	if (x > (1024 / 2) - 32 && x < (1024 / 2) + 32 && y > 10 && y < 64)
	{
		if (alive)
		{
			resetImage = &ResetImage_Alive_Pressed;
		}
		else
		{
			resetImage = &ResetImage_Dead_Pressed;
		}

	}
}

void MineManager::CheckResetButtonRelease(int x, int y)
{
	if (alive)
	{
		resetImage = &ResetImage_Alive_Unpressed;
	}
	else
	{
		resetImage = &ResetImage_Dead_Unpressed;
	}

	if (x > (1024 / 2) - 32 && x < (1024 / 2) + 32 && y > 0 && y < 64)
	{
		Reset();
	}
}

void MineManager::Draw()
{
	DrawTimer();
	DrawFlagCounter();
	DrawResetImage();
	DrawMines();
}

void MineManager::DrawTimer()
{
	DrawRectangle(10, 10, 400, 100, BLACK);
	int currentTime = timer.GetTime();
	DrawText(TextFormat("%05i", currentTime), 100, 17, 100, RED);
}

void MineManager::DrawFlagCounter()
{
	DrawRectangle(624, 10, 400, 100, BLACK);
	DrawText(TextFormat("%05i", flagCounter), 714, 17, 100, RED);
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
			if (mines[index].Interact(this))
			{
				winCounter++;
			}
		}
	}
}

void MineManager::DrawMines()
{
	for (int i = 0; i < total; i++)
	{
		mines[i].Draw(this, imageSizeMultiplyer);
	}
}

void MineManager::PressButton(int index)
{
	if (index >= 0 && index < total && alive)
	{
		if (mines[index].IsMine() && firsClick)
		{
			timer.StartTimer();
			mines[index].DisarmBomb();
			mines[0].ArmBomb();
			SetNearby();
		}
		else if(mines[index].IsMine() && !mines[index].IsFlagged())
		{
			alive = false;
			timer.StopTimer();
		}
		else if (firsClick)
		{
			timer.StartTimer();
		}
		firsClick = false;
		if (mines[index].Interact(this))
		{
			winCounter++;
			std::cout << winCounter << " != " << winCount << std::endl;
		}
	}

	if (alive && winCounter == winCount)
	{
		timer.StopTimer();
	}
}

void MineManager::PressButton(int mouseX, int mouseY)
{
	int rowIndex = 0;
	//added due to clicking above the minesweeper game could still interact with tiles below within 1 tile.
	if ((mouseY - (topGap)) > 0)
	{
		rowIndex = (mouseY - topGap) / buttonSize;
	}
	else
	{
		rowIndex = -1;
	}

	int colIndex = mouseX / buttonSize;

	int index = (rowIndex * xSize) + colIndex;

	PressButton(index);

}

void MineManager::RightClick(int mouseX, int mouseY)
{
	int rowIndex = 0;

	if ((mouseY - (topGap)) > 0)
	{
		rowIndex = (mouseY - topGap) / buttonSize;
	}
	else
	{
		rowIndex = -1;
	}

	int colIndex = mouseX / buttonSize;

	int index = (rowIndex * xSize) + colIndex;


	if (index >= 0 && index < total && alive)
	{
		if (mines[index].Flag())
		{
			flagCounter--;
		}
		else
		{
			flagCounter++;
		}
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

void MineManager::ArmBombs()
{
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
}

void MineManager::Reset()
{
	resetImage = &ResetImage_Alive_Unpressed;
	alive = true;
	for (int i = 0; i < total; i++)
	{
		mines[i].Reset();
	}
	firsClick = true;
	winCounter = 0;
	flagCounter = numOfMines;
	ArmBombs();
	SetNearby();
	timer.ResetTimer();
}

MineManager::~MineManager()
{
	//delete mines;
	//delete resetImage;
}








