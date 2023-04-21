#pragma once
#include <raylib.h>
#include "ImageManager.h"
#include "SoundManager.h"

class Menu
{
public:
	//constructors
	Menu(ImageManager* im, SoundManager* sm);
	~Menu();

	//draw function called every frame
	void Draw();

	//check if an button has been clicked
	void click(int mouseX, int mousY);
	//check if the mouse has eben released on the same button
	int release(int mouseX, int mouseY);
protected:
private:

	//booleans to store the previous click without a release
	bool easyClicked = false;
	bool mediumClicked = false;
	bool hardClicked = false;

	//set title position
	Vector2 titlePos = {112, 10};
	//set easy button position
	Vector2 easyPos = {212, 200};
	//set medium button position
	Vector2 mediumPos = {212, 450};
	//set thje hard button position
	Vector2 hardPos = {212,700};


	//pointers used to store the locations of the sound and image managers
	ImageManager* imageManager;
	SoundManager* soundManager;
};

