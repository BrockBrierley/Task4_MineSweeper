#include <iostream>
#include "raylib.h"
#include "mineButton.h";
#include "MineManager.h";

int main()
{
	const int WINDOW_WIDTH = 1080;
	const int WINDOW_HEIGHT = 1080;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MineSweeper");

	SetTargetFPS(60);
	//SetUp MineManager
	MineManager manager(10, 10);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		manager.DrawMines();

		EndDrawing();
	}
}