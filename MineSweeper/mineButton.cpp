#include "mineButton.h"
#include "MineManager.h"


//constructor and deconstructor are both empty as the object is declared in an array all at once and all need to have different values
//so the changes are created afterwards in a loop

/// <summary>
/// Donstructor
/// </summary>
mineButton::mineButton()
{
}

/// <summary>
/// Deconstructor
/// </summary>
mineButton::~mineButton()
{
}

/// <summary>
/// sets the x position of the button in the matrix and in the display window
/// </summary>
/// <param name="xPos">x position of this button in the display window</param>
/// <param name="x">x position in a 2d matrix</param>
void mineButton::SetX(int xPos, int x)
{
	pos.x = xPos;
	xArrayPos = x;
}

/// <summary>
/// sets the y position of the button in the 2d matrix and the display window
/// </summary>
/// <param name="yPos">y position in the display window</param>
/// <param name="y">y position in the 2d matrix</param>
void mineButton::SetY(int yPos, int y)
{
	pos.y = yPos;
	yArrayPos = y;
}

/// <summary>
/// arms the button to now contain a bomb
/// </summary>
void mineButton::ArmBomb()
{
	mine = true;
}

//disarms the button to no longer contain a bomb
//used on the first click to stop the user from dying first click
void mineButton::DisarmBomb()
{
	mine = false;
}

/// <summary>
/// sets the stored number of nearby mines to the number provided
/// </summary>
/// <param name="numOfMines">number of nearby mines</param>
void mineButton::SetNearbyMines(int numOfMines)
{
	nearby = numOfMines;
}

/// <summary>
/// returns the stored number of nearby mines
/// </summary>
/// <returns>number of nearby mines</returns>
int mineButton::GetNearby()
{
	return nearby;
}

/// <summary>
/// changes the state of this button to change betweena flagged button and a non flagged button
/// </summary>
/// <returns>returns 0 if the mine was flagged then returned to a normal state, 
/// returns 1 if the button was in a normal state and has been changed to a flage state
/// and returns -1 if there were no state changes</returns>
int mineButton::Flag()
{
	//check if the button is flagged
	if (flagged)
	{
		//change the flag state to normal
		flagged = false;
		//change the interactable state to interactable
		interactable = true;
		//return the state change number
		return 0;
	}
	//check if the button is both interactable and not a flag
	else if (!flagged && interactable)
	{
		//change the flag state to flagged
		flagged = true;
		//change the interactable state to non-interactable
		interactable = false;
		//return the state change number
		return 1;
	}
	//if there is no state changes return a negative number
	else
	{
		return -1;
	}
}

/// <summary>
/// Interact with the button based on its state.
/// </summary>
/// <param name="manager">the mine manager used to call this method, used to clear nearby squares if the clicked square has 0 nearby mines</param>
/// <returns>returns true if a button was successfully cleared. Used to increase the counter in the mineManager</returns>
bool mineButton::Interact(MineManager* manager)
{
	//check if the selected button is interactable
	if (interactable)
	{
		//change teh interactable state to false
		interactable = false;
		//change the revealed state to true
		revealed = true;

		//if the button contains a mine return false so the counter does not count down
		if (mine)
		{
			return false;
		}
		else
		{
			//if the number of nearby mines is 0 call the manager to clear all 9 nearby squares
			if (nearby == 0)
			{
				manager->ClearNearby(xArrayPos, yArrayPos);
			}
			//return true that this button has been successfully cleared
			return true;
		}
	}
}

/// <summary>
/// draw this current button based on its state.
/// </summary>
/// <param name="alive">the current alive state of the player</param>
/// <param name="imageSizeMultiplyer">image size multiplyer used to determine how big to draw the button images</param>
void mineButton::Draw(bool alive, float imageSizeMultiplyer)
{
	//sets variables to be used when calling the get image function to make it easier to determine the image needed
	int normal = 0;
	int flag = 1;
	int bomb = 2;

	//determined if this button has been clicked and contains a mine
	if (mine && revealed && clickedSquare)
	{
		//draw a red mine button
		DrawTextureEx(imageManager->GetBasicButton(bomb), pos, 0.0f, imageSizeMultiplyer, RED);
	}
	//displays a normal mine button when the player dies
	//checks if the button contains a mine and has been revealed but not clicked
	else if (mine && revealed)
	{
		//draw the basic mine without any colour changes
		DrawTextureEx(imageManager->GetBasicButton(bomb), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	//checks if the button has been flagged, contains a mine and the player has died
	else if (flagged && mine && !alive)
	{
		//draw the button as a green flag button to show the user they were correct when they flagged this position
		DrawTextureEx(imageManager->GetBasicButton(flag), pos, 0.0f, imageSizeMultiplyer, GREEN);
	}
	//determines if this button is flagged
	else if (flagged)
	{
		//draw this button as a flagged button
		DrawTextureEx(imageManager->GetBasicButton(flag), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	//determines if this button has been revealed
	else if (revealed)
	{
		//draws this button as a numbered button
		DrawTextureEx(imageManager->GetNumberedButton(nearby), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
	//if all other checks above fail draw this button as a basic unclicked button
	else
	{
		DrawTextureEx(imageManager->GetBasicButton(normal), pos, 0.0f, imageSizeMultiplyer, WHITE);
	}
}

/// <summary>
/// returns if this button contains a mine or not
/// </summary>
/// <returns>boolean containing if this button contains a mine</returns>
bool mineButton::IsMine()
{
	return mine;
}

/// <summary>
/// returns if this button has been flagged
/// </summary>
/// <returns>boolean containing the flag state</returns>
bool mineButton::IsFlagged()
{
	return flagged;
}

/// <summary>
/// resets this current button to its basic setting to restart the game
/// </summary>
void mineButton::Reset()
{
	mine = false;
	flagged = false;
	nearby = 0;
	interactable = true;
	revealed = false;
	clickedSquare = false;
}

/// <summary>
/// sets the image manager used to display the images used for this button.
/// </summary>
/// <param name="im"></param>
void mineButton::SetImageManager(ImageManager* imageMan)
{
	imageManager = imageMan;
}

