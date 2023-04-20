#include <iostream>
#include "raylib.h"
#include "mineButton.h";
#include "MineManager.h";
#include "Menu.h";
#include "SoundManager.h";
#include "ImageManager.h";


//To do
//create applicaiton object
//unload all images and sounds and anything else required in the deconstructors
//comment everything

void Update(MineManager* manager);
void Update(Menu* menu);
void Draw(MineManager* manager);
void Draw(Menu* menu);

const int TOP_GAP = 124;
bool menuActive = true;
int difficulty = 1;

int main()
{
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 1024;

	
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MineSweeper");
	InitAudioDevice();
	SoundManager* soundManager = new SoundManager();
	ImageManager* imageManager = new ImageManager();

	SetTargetFPS(60);
	//SetUp MineManager
	MineManager* manager = nullptr;
	Menu* menu = new Menu(imageManager, soundManager);

	while (!WindowShouldClose())
	{
		if (menuActive)
		{
			Update(menu);
			Draw(menu);
		}
		else if (!menuActive && manager == nullptr)
		{
			manager = new MineManager(TOP_GAP, difficulty, soundManager, imageManager);
		}
		else
		{
			Update(manager);
			Draw(manager);
		}
	}
}

void Update(MineManager* manager)
{

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		manager->PressButton(mousePos.x, mousePos.y);

		manager->CheckResetButtonPress(mousePos.x, mousePos.y);
	}

	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();
		manager->CheckResetButtonRelease(mousePos.x, mousePos.y);
	}


	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();
		manager->RightClick(mousePos.x, mousePos.y);
	}

	if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON))
	{
		manager->rightClickRelease();
	}
}

void Update(Menu* menu)
{
	int releaseNum = -1;
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		menu->click(mousePos.x, mousePos.y);
	}

	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();
		releaseNum = menu->release(mousePos.x, mousePos.y);
	}

	if (releaseNum >= 0)
	{
		difficulty = releaseNum;
		menuActive = false;
	}
}


void Draw(MineManager* manager)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	manager->Draw();

	EndDrawing();
}

void Draw(Menu* menu)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	menu->Draw();
	EndDrawing();
}