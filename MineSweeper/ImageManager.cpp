#include "ImageManager.h"


ImageManager::ImageManager()
{
	LoadImages();
}

ImageManager::~ImageManager()
{
	////Load Game Images
	//load Basic Images
	UnloadTexture(buttonImage);
	UnloadTexture(FlaggedImage);
	UnloadTexture(BombedImage);

	//flag image without the button
	UnloadTexture(flag);

	//Load Number Images
	UnloadTexture(EmptyImage);
	UnloadTexture(OneImage);
	UnloadTexture(TwoImage);
	UnloadTexture(ThreeImage);
	UnloadTexture(FourImage);
	UnloadTexture(FiveImage);
	UnloadTexture(SixImage);
	UnloadTexture(SevenImage);
	UnloadTexture(EightImage);

	//LoadResetButton Images
	UnloadTexture(ResetImage_Alive_Unpressed);
	UnloadTexture(ResetImage_Alive_Pressed);
	UnloadTexture(ResetImage_Dead_Unpressed);
	UnloadTexture(ResetImage_Dead_Pressed);


	////Load Menu Images
	UnloadTexture(title);
	UnloadTexture(easyPressed);
	UnloadTexture(easyUnpressed);
	UnloadTexture(mediumUnpressed);
	UnloadTexture(mediumPressed);
	UnloadTexture(hardUnpressed);
	UnloadTexture(hardPressed);
}

void ImageManager::LoadImages()
{
	////Load Game Images
	//load Basic Images
	buttonImage = LoadTexture("ArtAssets/Unknown_Unpressed_Button.png");
	FlaggedImage = LoadTexture("ArtAssets/Flagged_Button.png");
	BombedImage = LoadTexture("ArtAssets/Bomb_Button.png");

	//flag image without the button
	flag = LoadTexture("ArtAssets/flag.png");

	//Load Number Images
	EmptyImage = LoadTexture("ArtAssets/Empty_Pressed_Button.png");
	OneImage = LoadTexture("ArtAssets/1_Button.png");
	TwoImage = LoadTexture("ArtAssets/2_Button.png");
	ThreeImage = LoadTexture("ArtAssets/3_Button.png");
	FourImage = LoadTexture("ArtAssets/4_Button.png");
	FiveImage = LoadTexture("ArtAssets/5_Button.png");
	SixImage = LoadTexture("ArtAssets/6_Button.png");
	SevenImage = LoadTexture("ArtAssets/7_Button.png");
	EightImage = LoadTexture("ArtAssets/8_Button.png");

	//LoadResetButton Images
	ResetImage_Alive_Unpressed = LoadTexture("ArtAssets/HappyUnpressed.png");
	ResetImage_Alive_Pressed = LoadTexture("ArtAssets/HappyPressed.png");
	ResetImage_Dead_Unpressed = LoadTexture("ArtAssets/DeadUnpressed.png");
	ResetImage_Dead_Pressed = LoadTexture("ArtAssets/DeadPressed.png");


	////Load Menu Images
	title = LoadTexture("ArtAssets/title.png");
	easyUnpressed = LoadTexture("ArtAssets/EasyUnpressed.png");
	easyPressed = LoadTexture("ArtAssets/EasyPressed.png");
	mediumUnpressed = LoadTexture("ArtAssets/MediumUnpressed.png");
	mediumPressed = LoadTexture("ArtAssets/MediumPressed.png");
	hardUnpressed = LoadTexture("ArtAssets/HardUnpressed.png");
	hardPressed = LoadTexture("ArtAssets/HardPressed.png");
}



Texture2D ImageManager::GetNumberedButton(int number)
{
	switch (number)
	{
	case 0:
		return EmptyImage;
	case 1:
		return OneImage;
	case 2:
		return TwoImage;
	case 3:
		return ThreeImage;
	case 4:
		return FourImage;
	case 5:
		return FiveImage;
	case 6:
		return SixImage;
	case 7:
		return SevenImage;
	case 8:
		return EightImage;
	default:
		break;
	}
	return buttonImage;
}

Texture2D ImageManager::GetBasicButton(int number)
{
	switch (number)
	{
	case 0:
		return buttonImage;
	case 1:
		return FlaggedImage;
	case 2:
		return BombedImage;
	default:
		break;
	}
	return buttonImage;
}

Texture2D ImageManager::GetAliveResetImage(bool clicked)
{
	if (clicked)
	{
		return ResetImage_Alive_Pressed;
	}
	else
	{
		return ResetImage_Alive_Unpressed;
	}
}

Texture2D ImageManager::GetDeadResetImage(bool clicked)
{
	if (clicked)
	{
		return ResetImage_Dead_Pressed;
	}
	else
	{
		return ResetImage_Dead_Unpressed;
	}
}

Texture2D ImageManager::GetFlag()
{
	return flag;
}

Texture2D ImageManager::GetTitle()
{
	return title;
}

Texture2D ImageManager::GetEasy(bool clicked)
{
	if (clicked)
	{
		return easyPressed;
	}
	else
	{
		return easyUnpressed;
	}
}

Texture2D ImageManager::GetMed(bool clicked)
{
	if (clicked)
	{
		return mediumPressed;
	}
	else
	{
		return mediumUnpressed;
	}
}

Texture2D ImageManager::GetHard(bool clicked)
{
	if (clicked)
	{
		return hardPressed;
	}
	else
	{
		return hardUnpressed;
	}
}
