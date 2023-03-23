#include <iostream>
#include "raylib.h"
#include "mineButton.h";
#include "MineManager.h";

void Update(MineManager* manager, int mineX, int mineY);
void Draw(MineManager* manager);


int main()
{
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 1024;

	int mineFieldWidth = 16;
	int mineFieldHeight = 16;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MineSweeper");

	SetTargetFPS(60);
	//SetUp MineManager
	MineManager manager(mineFieldWidth, mineFieldHeight);

	while (!WindowShouldClose())
	{
		Update(&manager, mineFieldWidth, mineFieldWidth);
		Draw(&manager);
	}
}

void Update(MineManager* manager, int mineX, int mineY)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();
		int rowIndex = mousePos.y / 64;
		int colIndex = mousePos.x / 64;

		int index = (rowIndex * mineX) + colIndex;
		manager->PressButton(index);
	}

	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();
		int rowIndex = mousePos.y / 64;
		int colIndex = mousePos.x / 64;

		int index = (rowIndex * mineX) + colIndex;
		manager->RightClick(index);
	}
}

void Draw(MineManager* manager)
{
	BeginDrawing();
	ClearBackground(GREEN);

	manager->DrawMines();

	EndDrawing();
}