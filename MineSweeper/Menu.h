#pragma once
#include <raylib.h>

class Menu
{
public:
	Menu();
	~Menu();
	void Draw();
	int click(int mouseX, int mousY);
protected:
private:
	Texture2D Title;
	Texture2D easyUnpressed;
	Texture2D easyPressed;
	Texture2D mediumUnpressed;
	Texture2D mediumPressed;
	Texture2D hardUnpressed;
	Texture2D hardPressed;

	bool easyClicked = false;
	bool mediumClicked = false;
	bool hardClicked = false;

	Vector2 titlePos = {112, 10};
	Vector2 easyPos = {212, 200};
	Vector2 mediumPos = {212, 450};
	Vector2 hardPos = {212,700};
};

