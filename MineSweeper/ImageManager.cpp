#include "ImageManager.h"


/// <summary>
/// Constructor for the ImageManager object
/// will load in all images when created
/// </summary>
ImageManager::ImageManager()
{
	LoadImages();
}

/// <summary>
/// Deconstructor will delete all images loaded in with this object
/// </summary>
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

/// <summary>
/// Method used when constructing the object, will load in all the images
/// </summary>
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


/// <summary>
/// Getter to return the numbered image for a mine square
/// </summary>
/// <param name="number">number used to determine which image will be returned</param>
/// <returns>image with the number passed in via the parameter on it</returns>
Texture2D ImageManager::GetNumberedButton(int number)
{
	//switch case which will return the corresponmding image to the selected number
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

/// <summary>
/// returns the basic mine button image (0), flag button image(1), or the bomb button image(2)
/// </summary>
/// <param name="number">integer to select the button image type</param>
/// <returns>image to be drawn as a minebutton</returns>
Texture2D ImageManager::GetBasicButton(int number)
{
	//swqitch case to determine which image to return based on the paramter
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

/// <summary>
/// Returns the alive reset button image
/// </summary>
/// <param name="clicked">boolean to determine if the mouse button is currently down</param>
/// <returns>image with either a clicked or unclicked Alive reset button</returns>
Texture2D ImageManager::GetAliveResetImage(bool clicked)
{
	//if the button is clicked return the pressed button
	if (clicked)
	{
		return ResetImage_Alive_Pressed;
	}
	//else return the normal unpressed button
	else
	{
		return ResetImage_Alive_Unpressed;
	}
}

/// <summary>
/// Returns the dead reset button image.
/// </summary>
/// <param name="clicked">Boolean which determines if the button is currently clicked or not</param>
/// <returns>clicked or unclicked image based on the input parameter</returns>
Texture2D ImageManager::GetDeadResetImage(bool clicked)
{
	//if the button is clicked return the dead pressed image
	if (clicked)
	{
		return ResetImage_Dead_Pressed;
	}
	//if the button is not pressed return the dead unpressed image
	else
	{
		return ResetImage_Dead_Unpressed;
	}
}

/// <summary>
/// returns a basic flag image to be used next to the flag counter
/// </summary>
/// <returns></returns>
Texture2D ImageManager::GetFlag()
{
	return flag;
}


/// <summary>
/// returnt the title image used on the main menu
/// </summary>
/// <returns></returns>
Texture2D ImageManager::GetTitle()
{
	return title;
}

/// <summary>
/// returns the easy button, either clicked or unclicked based on the input boolean
/// </summary>
/// <param name="clicked">boolean to determine if the button is clicked or not</param>
/// <returns>either the clicked or unclicked easy button image</returns>
Texture2D ImageManager::GetEasy(bool clicked)
{
	//if the button is clicked retunr the pressed easy button
	if (clicked)
	{
		return easyPressed;
	}
	//if the button is not clicked return the unpressed easy button
	else
	{
		return easyUnpressed;
	}
}

/// <summary>
/// returns the medium button, either clicked or unclicked based on the input boolean
/// </summary>
/// <param name="clicked"> boolean to determin if the button is clicked</param>
/// <returns>Medium button image</returns>
Texture2D ImageManager::GetMed(bool clicked)
{
	//if the button is clicked return the clicked medium button image
	if (clicked)
	{
		return mediumPressed;
	}
	//if the button is not clicked return the unclicked medium button image
	else
	{
		return mediumUnpressed;
	}
}

/// <summary>
/// returns the hard button image. Either clicked or unclicked based on the input boolean
/// </summary>
/// <param name="clicked">boolean to determine if the button is clicked or not</param>
/// <returns>Hard button image</returns>
Texture2D ImageManager::GetHard(bool clicked)
{
	//if the button is clicked return the clicked hard button
	if (clicked)
	{
		return hardPressed;
	}
	//if the button is not clicked return the unclicked hard button.
	else
	{
		return hardUnpressed;
	}
}
