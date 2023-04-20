#pragma once
#include <raylib.h>
#include "ImageManager.h"

class Menu
{
public:
	Menu(ImageManager* iM);
	~Menu();
	void Draw();
	void click(int mouseX, int mousY);
	int release(int mouseX, int mouseY);
protected:
private:

	bool easyClicked = false;
	bool mediumClicked = false;
	bool hardClicked = false;

	Vector2 titlePos = {112, 10};
	Vector2 easyPos = {212, 200};
	Vector2 mediumPos = {212, 450};
	Vector2 hardPos = {212,700};

	ImageManager* imageManager;
};

