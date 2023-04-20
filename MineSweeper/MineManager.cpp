#include "MineManager.h"
#include <iostream>

MineManager::MineManager(int gap, int difficulty, SoundManager* soundMan, ImageManager* imageMan)
{
	//set manager pointers
	soundManager = soundMan;
	imageManager = imageMan;

	//set the input top gap for the mines
	topGap = gap;
	
	//set the number of mines and buttons based on input difficulty
	if (difficulty == 0)
	{
		numOfMines = 8;
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
		numOfMines = 150;
		xSize = 32;
		ySize = 28;
		buttonSize /= 2;
		imageSizeMultiplyer = 0.5f;
	}
	//default if there is an unknown input number for difficulty
	else
	{
		numOfMines = 30;
		xSize = 16;
		ySize = 14;
	}

	//set the starting image for the reset button
	resetImage = imageManager->GetAliveResetImage(false);
	//set the x and y position for the starting button
	//half the screen size minus half the image size
	resetPos.x = ((1024 / 2) - 32);
	//10 pixels from the top of the screen
	resetPos.y = 10;

	//total number of mine buttons
	total = xSize * ySize;

	//set the wincount (number of revealed squares) to equal the total minus the number of mines
	winCount = total - numOfMines;

	//set the starting number for the flag counter
	flagCounter = numOfMines;

	//create 1d array the list of mines
	//wouldve used a 2d array but it is not possible to do inside a constructor for an object to my knowledge
	mines = new mineButton[total];

	//iterate through the list of buttons and set the image manager, x position and y position for all buttons
	for (int i = 0; i < total; i++)
	{
		mines[i].SetImageManager(imageManager);
		mines[i].SetX( ((i % xSize)*buttonSize), i % xSize);
		mines[i].SetY( ((i / xSize)*buttonSize) + topGap, i / xSize);
	}

	//set up mines in all buttons
	ArmBombs();

	//calculate all nearby mines and update all buttons to contain the right number
	SetNearby();
}    

/// <summary>
/// Draw the reset button on the screen
/// </summary>
void MineManager::DrawResetImage()
{
	DrawTextureEx(resetImage, resetPos, 0.0f, 1.0f, WHITE);
}

/// <summary>
/// check if the reset button has been clicked
/// </summary>
/// <param name="xMouse">x position of the mouse</param>
/// <param name="yMouse">y position of the mouse</param>
void MineManager::CheckResetButtonPress(int xMouse, int yMouse)
{
	//check if mouse position is over the reset button
	if (xMouse > (1024 / 2) - 32 && xMouse < (1024 / 2) + 32 && yMouse > 10 && yMouse < 64)
	{
		//play the click in sound
		soundManager->PlayClickIn();
		//set left clicked state to true
		leftCLicked = true;
		resetButtonClicked = true;

		//update the clicked image to be drawn based on whether the player is alive or dead
		if (alive)
		{
			resetImage = imageManager->GetAliveResetImage(true);
		}
		else
		{
			resetImage = imageManager->GetDeadResetImage(true);
		}

	}
}

/// <summary>
/// Check if the player has released the mouse over the reset button
/// </summary>
/// <param name="xMouse">x position of the mouse</param>
/// <param name="yMouse">y position of the mouse</param>
void MineManager::CheckResetButtonRelease(int xMouse, int yMouse)
{
	//if the leftclicked state is true then change it to false
	//and play the release click button sound
	if (leftCLicked)
	{
		leftCLicked = false;
		soundManager->PlayClickOut();
	}
	//update the button to draw the released button based on whether the player is alive or dead
	if (alive)
	{
		resetImage = imageManager->GetAliveResetImage(false);
	}
	else
	{
		resetImage = imageManager->GetDeadResetImage(false);
	}

	//if the mouse was released over the reset button after it has been clicked, reset the game
	if (xMouse > (1024 / 2) - 32 && xMouse < (1024 / 2) + 32 && yMouse > 0 && yMouse < 64 && resetButtonClicked)
	{
		resetButtonClicked = false;
		Reset();
	}
}

/// <summary>
/// Calls all draw functions for all objects controlled by this manager
/// </summary>
void MineManager::Draw()
{
	DrawTimer();
	DrawFlagCounter();
	DrawResetImage();
	DrawMines();
}

/// <summary>
/// Draws the timer at the top left of the screen
/// </summary>
void MineManager::DrawTimer()
{
	//draw the black background rectangle
	DrawRectangle(10, 10, 400, 100, BLACK);
	//get the current time on the timer
	int currentTime = timer.GetTime();
	//draw the time as text inside the black rectangle
	DrawText(TextFormat("%05i", currentTime), 100, 17, 100, RED);
}

/// <summary>
/// draws the flag counter at the top right of the screen
/// </summary>
void MineManager::DrawFlagCounter()
{
	//draw a black rectanlge being the counter
	DrawRectangle(624, 10, 400, 100, BLACK);
	//draw the counter number inside the square
	DrawText(TextFormat("%05i", flagCounter), 714, 17, 100, RED);
	//create temp position vec2 for the flag
	Vector2 flagPos = { 605, 0 };
	//draw the flag inside the black rectangle next to the counter
	DrawTextureEx(imageManager->GetFlag(), flagPos, 0, 2, WHITE);
}

/// <summary>
/// Interates through all buttons in the array and sets the nearby mine number value.
/// </summary>
void MineManager::SetNearby()
{
	//For Loop GALORE, You get a for loop and you get a for loop.

	//iterate through a 2d matrix
	for (int y = 0; y < ySize; y++)
	{
		for (int x = 0; x < xSize; x++)
		{
			//set nearby mine counter to 0
			int counter = 0;
			//create a starting x and y position variable for the next for loop
			int startingY;
			int startingX;
			//create an ending x and y position variable for the for loop
			int endingY;
			int endingX;

			//calcuate the start point and end point for each axis to check nearby mines
			//check if the current button is on the top of the matrix
			if (y == 0)
			{
				//set the starting row to the same row as the button
				startingY = 0;
			}
			else
			{
				//set the starting row to the rowqq above the button
				startingY = -1;
			}

			//Check if the current button is on the bottom row of the matrix
			if (y == ySize-1)
			{
				//set the ending row to the same as the button
				endingY = 0;
			}
			else
			{
				//set the ending row to be after the button
				endingY = 1;
			}
			
			//check to see if the button is on the left column of the matrix
			if (x == 0)
			{
				//set the starting column to be the same as the button
				startingX = 0;
			}
			else
			{
				//set the starting column to be the column before this button
				startingX = -1;
			}

			//check if the button is on the far right column
			if (x == xSize - 1)
			{
				//set the ending column to be the same as the button
				endingX = 0;
			}
			else
			{
				//set the ending column to be the column after the button
				endingX = 1;
			}

			//for using the starting and ending values above to determine the number of mines in the surrounding 8 squares
			//this loop does include the button checking, this isnt an issue though as if the button contains a mine it will not display
			//the number of nearby mines
			for (int yNearby = startingY; yNearby <= endingY; yNearby++)
			{
				for (int xNearby = startingX; xNearby <= endingX; xNearby++)
				{
					//calculate the index of a 1d array using 2d coordinates
					int index = ((y + yNearby) * xSize) + (x + xNearby);
					//increase the counter if the nearby button contains a mine
					if (mines[index].IsMine())
					{
						counter++;
					}
				}
			}

			//calculate the index of the current mine that is being checked
			int index = (y * xSize) + x;
			//update the mines nearby variable
			mines[index].SetNearbyMines(counter);
		}
	}
}

/// <summary>
/// clears the surrounding buttons from the index of x and y if the button clicked has 0 nearby mines
/// </summary>
/// <param name="x">x position of the clicked button</param>
/// <param name="y">y position of the clicked button</param>
void MineManager::ClearNearby(int x, int y)
{
	///this works similar to the method above but it does not need to iterate through all the mines , so it only does the final 2 iterations
	
	//create starting and ending variables
	int startingY;
	int startingX;
	int endingY;
	int endingX;

	//calcuate the start point and end point for each axis to check nearby mines
	//check if the input position is on the top row
	if (y == 0)
	{
		startingY = 0;
	}
	else
	{
		startingY = -1;
	}

	//check if the input button is on the bottom row
	if (y == ySize - 1)
	{
		endingY = 0;
	}
	else
	{
		endingY = 1;
	}


	//check if the input button is on the left column
	if (x == 0)
	{
		startingX = 0;
	}
	else
	{
		startingX = -1;
	}

	//check if the input button is on the right column
	if (x == xSize - 1)
	{
		endingX = 0;
	}
	else
	{
		endingX = 1;
	}

	//for loop to interact with the 8 nearby buttons
	for (int yNearby = startingY; yNearby <= endingY; yNearby++)
	{
		for (int xNearby = startingX; xNearby <= endingX; xNearby++)
		{
			//callcuate the index based on the x and y value of the iterations
			int index = ((y + yNearby) * xSize) + (x + xNearby);
			//iteract with the button
			if (mines[index].Interact(this))
			{
				//increase the counter if the button is interacted with
				winCounter++;
			}
		}
	}
}

/// <summary>
/// iterates through the array of buttons and calls its draw function
/// </summary>
void MineManager::DrawMines()
{
	for (int i = 0; i < total; i++)
	{
		mines[i].Draw(alive, imageSizeMultiplyer);
	}
}

/// <summary>
/// iterates through all the buttons and interacts with all buttons containing the mines
/// </summary>
void MineManager::ShowAllMines()
{
	for (int i = 0; i < total; i++)
	{
		if (mines[i].IsMine())
		{
			//interact simply makes the button non interactable and to display the hidden data
			//therefore it works fine to use here instead of creating another special function
			mines[i].Interact(this);
		}
	}
}

/// <summary>
/// takes the index of a button then clicks it based on the state of the given button
/// </summary>
/// <param name="index">index of the button</param>
void MineManager::PressButton(int index)
{
	//check if the player i still alive before interacting with the button
	//and check to make sure the index is positive
	if (index >= 0 && index < total && alive)
	{
		//if the first button clicked is a mine, relocate the mine into the top left square then recalculates nearby mines
		if (mines[index].IsMine() && firsClick)
		{
			//start the timer
			timer.StartTimer();
			//removes the bomb from this button
			mines[index].DisarmBomb();
			//add in a bomb to the top left button
			mines[0].ArmBomb();
			//recalculate the nearby mines
			SetNearby();
		}
		//test if the button contains a mine and is not flagged
		else if (mines[index].IsMine() && !mines[index].IsFlagged())
		{
			//kill the player (in the game please not real life)
			alive = false;
			//update the buttons clicked square styate to display it as red
			mines[index].clickedSquare = true;
			//play the explosion noise loaded in the sound manager
			soundManager->PlayExplosion();
			//iterate through all mines and display their locations
			ShowAllMines();
			//stop the timer
			timer.StopTimer();
		}
		//if this the first button clicked and there are no mines inside it start the timer
		else if (firsClick)
		{
			//start the timer
			timer.StartTimer();
		}
		//set first click state to false
		firsClick = false;
		//call the buttons interact function
		if (mines[index].Interact(this))
		{
			//increase the win counter
			winCounter++;
		}
	}

	//test if the last click as won the player the game
	if (alive && winCounter == winCount)
	{
		//if yes stop the timer
		timer.StopTimer();
	}
}

/// <summary>
/// Press function button which will take the x and y position of the mouse click and calculate the button that has been clicked
/// this allows both the mouse position or the index to be used to click a button
/// </summary>
/// <param name="mouseX">x position of the click</param>
/// <param name="mouseY">y position of the click</param>
void MineManager::PressButton(int mouseX, int mouseY)
{
	//set the row index to 0
	int rowIndex = 0;
	//added due to clicking above the minesweeper game could still interact with tiles below within 1 tile.
	//check to see if the mouse click location is within the game space
	if ((mouseY - (topGap)) > 0)
	{
		//calcuate teh row index by minusing the top game and dividing thge size of each button
		rowIndex = (mouseY - topGap) / buttonSize;
		//play kick in sound
		soundManager->PlayClickIn();
		//set left click state to true
		leftCLicked = true;
	}
	//if the click is outside the gamespace set the index to negative 1
	else
	{
		rowIndex = -1;
	}

	//calculate the column of the click position
	int colIndex = mouseX / buttonSize;

	//calculate the 1d array index using 2d coordinates
	int index = (rowIndex * xSize) + colIndex;

	//call the press button function with an index as the argument
	PressButton(index);

}

/// <summary>
/// calculates if a button has been right clicked
/// </summary>
/// <param name="mouseX">x position of the right click</param>
/// <param name="mouseY">y position of the right click</param>
void MineManager::RightClick(int mouseX, int mouseY)
{
	//sets initial row index
	int rowIndex = 0;

	//minus the top gap from the calculated row
	if ((mouseY - (topGap)) > 0)
	{
		//calculate the row index
		rowIndex = (mouseY - topGap) / buttonSize;
		//play the click press sound
		soundManager->PlayClickIn();
		//set right click state to true
		rightClicked = true;
	}
	//sets the row index to -1 if the rightclick is outside the game space
	else
	{
		rowIndex = -1;
	}

	//calculate the column index
	int colIndex = mouseX / buttonSize;

	//calculate the 1d index from a 2d index
	int index = (rowIndex * xSize) + colIndex;


	//check if the index is positive and the player is alive
	if (index >= 0 && index < total && alive)
	{
		//flag the button at the index and get teh returned int to determine the state of the flag
		int flagged = mines[index].Flag();
		//if the button was flagged minus 1 from the flag counter
		if (flagged == 1)
		{
			flagCounter--;
		}
		//if the flag is removed re-add a flag to the counter
		else if (flagged == 0)
		{
			flagCounter++;
		}
	}
}

/// <summary>
/// check if the user has released their right click button
/// </summary>
void MineManager::rightClickRelease()
{
	if (rightClicked)
	{
		//reset right clicked state
		rightClicked = false;
		//play the release click sound
		soundManager->PlayClickOut();
	}
}


/// <summary>
/// uses random to select random buttons within the array size
/// </summary>
void MineManager::ArmBombs()
{
	//repeats until the number of required mines are created
	for (int i = 0; i < numOfMines; i++)
	{
		//get a random number between 0 and the total, excludes the total
		//minus 1 before the % and plus 1 after the to ensure mines are not places in the 0 slot which is the failsafe
		//point if the user clicks on a mine
		int randomNum = (rand() % (total - 1)) + 1;
		//rerun if the position already contains a mine
		while (mines[randomNum].IsMine())
		{
			randomNum = (rand() % (total - 1)) + 1;
		}
		//uses the random index generated to arm the specific button at that index
		mines[randomNum].ArmBomb();
	}
}

/// <summary>
/// resets the game with random values
/// </summary>
void MineManager::Reset()
{
	//updates the reset image to be back to the alive image
	resetImage = imageManager->GetAliveResetImage(false);
	//set player status to alive
	alive = true;

	//iterate through all mines and use their reset function
	for (int i = 0; i < total; i++)
	{
		mines[i].Reset();
	}
	//reset the first click state
	firsClick = true;
	//clear the win counter
	winCounter = 0;
	//reset the flag counter to equal the number of mines
	flagCounter = numOfMines;
	//arm the minefield
	ArmBombs();
	//set the nearby count numbers for each button
	SetNearby();
	//resete the timer
	timer.ResetTimer();
}

//returns if the player is still alive
bool MineManager::IsAlive()
{
	return alive;
}

MineManager::~MineManager()
{

}








