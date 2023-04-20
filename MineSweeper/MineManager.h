#pragma once
#include "raylib.h"
#include "mineButton.h"
#include "Timer.h"
#include "SoundManager.h"
#include "ImageManager.h"

class MineManager
{
public:
	//constructor and destructor
	MineManager( int topGap, int difficulty, SoundManager* sm, ImageManager* im);
	~MineManager();

	//draw the mines to the screen
	void DrawMines();
	//call all draw functions
	void Draw();
	//presses the button at the given index
	void PressButton(int Index);
	//calculates an index and calls the same function but uses the index
	void PressButton(int mouseX, int mouseY);
	//checks if the user right clicks a button
	void RightClick(int mouseX, int mouseY);
	//plays the release click sound when releasing the right click
	void rightClickRelease();
	//iterates around the given 2d index to interact with nearby buttons
	void ClearNearby(int x, int y);
	//draws the reset button image to the screen
	void DrawResetImage();
	//calculates if the reset button is clicked
	void CheckResetButtonPress(int x, int y);
	//calculates if the reset button is released
	void CheckResetButtonRelease(int x, int y);
	//arms random bombs throughout the minefield
	void ArmBombs();
	//shows all mine locations when the player dies
	void ShowAllMines();
	//returns if the player is alive
	bool IsAlive();

protected:
private:
	//iterates through the array, then iterates around each index and calculates all nearby minesz
	void SetNearby();
	//resets all values to a new game state
	void Reset();
	//position for the reset button to be located
	Vector2 resetPos;
	//number ofbuttons on the x axis
	int xSize;
	//number of buttons on the y axis
	int ySize;
	//xaxis *yaxis to calculate the total number of buttons in the minefield
	int total;
	//total number of mines
	int numOfMines;
	//the size in pizels of the button used in the minefield
	int buttonSize = 64;
	//array containing all the buttons in the minefield
	mineButton* mines;
	//boolean containing the alive state of the player
	bool alive = true;
	//boolean containing the first click state
	bool firsClick = true;
	//timer object used to display the time on the top left
	Timer timer;
	//draw the timer on the top left of the screen
	void DrawTimer();
	//draw the flag counter on the top right of the screen
	void DrawFlagCounter();
	//gap at the top of the screen
	int topGap;

	//sets wincount to negative to begin with so that the player doesnt win as soon as the game starts
	int winCount = -1;
	//win counter hold the number of successful buttons cleared
	int winCounter = 0;
	//flag counter counts the remaining mines unflagged/ how many flags the user should be using
	int flagCounter = 0;
	//image size multiplyer used when drawing the images to change the size of each button
	float imageSizeMultiplyer = 1;

	//soudn and image managers
	SoundManager* soundManager;
	ImageManager* imageManager;

	//Stored pointer to the resetImage
	Texture2D resetImage;

	//click states for playing sound
	bool leftCLicked = false;
	bool rightClicked = false;
	bool resetButtonClicked = false;
};

