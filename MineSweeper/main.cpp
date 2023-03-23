#include <iostream>
#include "raylib.h"
#include "mineButton.h";

int main()
{
	const int WINDOW_WIDTH = 1080;
	const int WINDOW_HEIGHT = 1080;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MineSweeper");

	SetTargetFPS(60);

	mineButton button;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		button.Draw();

		EndDrawing();
	}
}