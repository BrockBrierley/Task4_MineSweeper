#include <iostream>
#include "raylib.h"
#include "mineButton.h";
#include "MineManager.h";
#include "Menu.h";

void Update(MineManager* manager);
void Draw(MineManager* manager);
void Draw(Menu* menu);

const int TOP_GAP = 124;
bool menuActive = true;

int main()
{

	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 1024;

	const int EASY = 0;
	const int MEDIUM = 1;
	const int HARD = 2;


	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MineSweeper");

	SetTargetFPS(60);
	//SetUp MineManager
	MineManager* manager = new MineManager(TOP_GAP, MEDIUM);
	Menu* menu = new Menu();

	while (!WindowShouldClose())
	{
		if (menuActive)
		{
			Draw(menu);
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