#pragma once
#include "raylib.h"

class ImageManager
{
public:
	ImageManager();
	~ImageManager();
	//basic game Get Methods
	Texture2D GetNumberedButton(int number);
	Texture2D GetBasicButton(int number);
	Texture2D GetAliveResetImage(bool clicked);
	Texture2D GetDeadResetImage(bool clicked);

	//plainFlag
	Texture2D GetFlag();

	//Menu Get Methods
	Texture2D GetTitle();
	Texture2D GetEasy(bool clicked);
	Texture2D GetMed(bool clicked);
	Texture2D GetHard(bool clicked);
protected:
private:
	void LoadImages();
	/////Image variables
	//Game Images
	//Basic buttons
	Texture2D buttonImage;
	Texture2D FlaggedImage;
	Texture2D BombedImage;

	//flag image used in the falg counter
	Texture2D flag;

	//Number Buttons
	Texture2D EmptyImage;
	Texture2D OneImage;
	Texture2D TwoImage;
	Texture2D ThreeImage;
	Texture2D FourImage;
	Texture2D FiveImage;
	Texture2D SixImage;
	Texture2D SevenImage;
	Texture2D EightImage;

	//load reset button textures
	Texture2D ResetImage_Alive_Unpressed;
	Texture2D ResetImage_Alive_Pressed;
	Texture2D ResetImage_Dead_Unpressed;
	Texture2D ResetImage_Dead_Pressed;


	//Menu Images
	Texture2D title;
	Texture2D easyUnpressed;
	Texture2D easyPressed;
	Texture2D mediumUnpressed;
	Texture2D mediumPressed;
	Texture2D hardUnpressed;
	Texture2D hardPressed;
};

