#include <iostream>
#include "raylib.h"
#include "mineButton.h";
#include "MineManager.h";
#include "Menu.h";
#include "SoundManager.h";
#include "ImageManager.h";

//set up functions to be defined below
void Update(MineManager* manager);
void Update(Menu* menu);
void Draw(MineManager* manager);
void Draw(Menu* menu);

//create a constant global variable to hold the size at the top of the game field
const int TOP_GAP = 124;

//create a global variables to be pick up by the on click events instead of passing it every update
bool menuActive = true;
int difficulty = 1;

int main()
{
	//Set COnstants for the window width and height
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 1024;

	
	//Initialise raylib window
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MineSweeper");
	//Initialise audio devices
	InitAudioDevice();

	//create the sound manager and image manager which will be used by all classes
	//so that multiple of the same image and sound are not needed to be loaded
	SoundManager* soundManager = new SoundManager();
	ImageManager* imageManager = new ImageManager();

	//set the target fps
	SetTargetFPS(60);

	//Create mine manager pointer to be stored as null until the player has decided the game difficulty
	MineManager* manager = nullptr;

	//create the menu object which will control the menu
	Menu* menu = new Menu(imageManager, soundManager);

	//application while loop, this runs ever frame
	while (!WindowShouldClose())
	{
		//if the menu is update with themenu functions
		if (menuActive)
		{
			Update(menu);
			Draw(menu);
		}
		//Create a mineManager when the menu is closed/ a difficulty is selected
		else if (!menuActive && manager == nullptr)
		{
			manager = new MineManager(TOP_GAP, difficulty, soundManager, imageManager);
		}
		//update the game with using the mineManager
		else
		{
			Update(manager);
			Draw(manager);
		}
	}
	//delete all pointers when not in use
	delete (manager);
	delete (soundManager);
	delete (imageManager);
}

/// <summary>
/// Function called every frame to update the main game
/// </summary>
/// <param name="manager">the mineManager used to control and display all mines</param>
void Update(MineManager* manager)
{
	//check if the mouse has clicked any game buttons
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		//get the mouse position
		Vector2 mousePos = GetMousePosition();

		//check if the mouse has clicked a mine button
		manager->PressButton(mousePos.x, mousePos.y);

		//check if the mouse has clicked the reset button
		manager->CheckResetButtonPress(mousePos.x, mousePos.y);
	}

	//release check used to update the drawn images and sounds
	//this is unnecessary tp the core gameplay, but allows feedback to the player to feel like they are pressing the button
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
	{
		//get the mouse position
		Vector2 mousePos = GetMousePosition();
		
		//Check if the mouse button is still over the reset button to allow a failsafe of moving the mouse before releasing 
		//to not click the button
		manager->CheckResetButtonRelease(mousePos.x, mousePos.y);
	}


	//check if the right mouse button is pressed
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		//get the location of the mouse
		Vector2 mousePos = GetMousePosition();

		//check if the mouse has right clicked a not flagged mine button
		manager->RightClick(mousePos.x, mousePos.y);
	}

	//play the release sound for the player feedback when the mouse button is released
	if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON))
	{
		manager->rightClickRelease();
	}
}

/// <summary>
/// Function called every frame to update the menu
/// </summary>
/// <param name="menu">menu object which will control the screen</param>
void Update(Menu* menu)
{
	//release num is used to determine which button the used has pressed, starts at negetive to ensure it will not
	//not automatically determine the difficulty and will wait for the proper input
	int releaseNum = -1;

	//get the mouse position and check if it has clicked on one of the on screen buttons
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		//get the mouse position
		Vector2 mousePos = GetMousePosition();

		//check if the mouse clicked on the easy medium or hard button
		menu->click(mousePos.x, mousePos.y);
	}

	//check when the mouse button is released
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
	{
		//get the mouse position on release
		Vector2 mousePos = GetMousePosition();
		//check if the mouse was released over the same button clicked
		//if yes the difficulty number is returned
		releaseNum = menu->release(mousePos.x, mousePos.y);
	}

	//if the difficulty number is changed to a positive number then deactivate the menu
	if (releaseNum >= 0)
	{
		difficulty = releaseNum;
		menuActive = false;
	}
}


/// <summary>
/// Draw phase for the main game
/// </summary>
/// <param name="manager">Mine manager used to draw the game</param>
void Draw(MineManager* manager)
{
	//begin the draw phase
	BeginDrawing();
	//clear the screen
	ClearBackground(RAYWHITE);

	//draw the game screen
	manager->Draw();

	//end the draw phase
	EndDrawing();
}

/// <summary>
/// Draw phase for the main menu
/// </summary>
/// <param name="menu">menu object to draw</param>
void Draw(Menu* menu)
{
	//begin the draw phase
	BeginDrawing();
	//clear the screen
	ClearBackground(RAYWHITE);
	//draw the menu
	menu->Draw();
	//end the drawr phase
	EndDrawing();
}