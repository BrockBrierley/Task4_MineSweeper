#include "Menu.h"

//constructor which will set the image and sound manager pointers on creation.
Menu::Menu(ImageManager* imageMan, SoundManager* soundMan)
{
	imageManager = imageMan;
	soundManager = soundMan;
}

Menu::~Menu()
{

}

/// <summary>
/// draw the menu items
/// </summary>
void Menu::Draw()
{
	//draw the title at the top of the screen
	DrawTextureEx(imageManager->GetTitle(), titlePos, 0.0f, 1.0f, WHITE);

	//check if the easy button is clicked and draw the corresponding image
	if (easyClicked)
	{
		DrawTextureEx(imageManager->GetEasy(true), easyPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(imageManager->GetEasy(false), easyPos, 0.0f, 1.0f, WHITE);
	}

	//check if the medium button is clicked and draw the corresponding image
	if (mediumClicked)
	{
		DrawTextureEx(imageManager->GetMed(true), mediumPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(imageManager->GetMed(false), mediumPos, 0.0f, 1.0f, WHITE);
	}

	//check if the hard button is clicked and draw the corresponding image
	if (hardClicked)
	{
		DrawTextureEx(imageManager->GetHard(true), hardPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(imageManager->GetHard(false), hardPos, 0.0f, 1.0f, WHITE);
	}

}


/// <summary>
/// click method called from the main loop whenever the mouse button is clicked
/// </summary>
/// <param name="mouseX">mouses x position</param>
/// <param name="mouseY">mouses y position</param>
void Menu::click(int mouseX, int mouseY)
{
	//determine if the mouse has clicked the easy button, if yes play the click sound
	//and set easyClicked to true
	if (mouseX > easyPos.x && mouseX < easyPos.x + 600 && mouseY > easyPos.y && mouseY < easyPos.y +200)
	{
		soundManager->PlayClickIn();
		easyClicked = true;
	}

	//determine if the mouse has clicked the medium button
	else if (mouseX > mediumPos.x && mouseX < mediumPos.x + 600 && mouseY > mediumPos.y && mouseY < mediumPos.y + 200)
	{
		soundManager->PlayClickIn();
		mediumClicked = true;
	}
	//determine if the mouse has clicked the hard button
	else if (mouseX > hardPos.x && mouseX < hardPos.x + 600 && mouseY > hardPos.y && mouseY < hardPos.y + 200)
	{
		soundManager->PlayClickIn();
		hardClicked = true;
	}
}

/// <summary>
/// checks to see if the mouse is released on the same button it has been clicked on
/// used as a basic failsafe if the user clicks the wrong button, the mouse can be slid off the button and then released 
/// to not activate it
/// Also adds a feedback to the player as they can see the button be pressed and released when clicking
/// </summary>
/// <param name="mouseX">mouses x position</param>
/// <param name="mouseY">mouses y position</param>
/// <returns>returns the difficulty back to the main loop</returns>
int Menu::release(int mouseX, int mouseY)
{
	//set a negative difficulty so the game will select a preset difficulty
	int difficulty = -1;
	//check if the mous was previously clicked on the easy and has been released on easy
	if (mouseX > easyPos.x && mouseX < easyPos.x + 600 && mouseY > easyPos.y && mouseY < easyPos.y + 200 && easyClicked)
	{
		//set the difficulty to easy (0)
		difficulty = 0;
	}

	//check if the mouse has previous clicked on medium and has been released on medium
	else if (mouseX > mediumPos.x && mouseX < mediumPos.x + 600 && mouseY > mediumPos.y && mouseY < mediumPos.y + 200 && mediumClicked)
	{
		//set the difficulty to medium difficulty
		difficulty = 1;
	}

	//check if the mouse has previously clicked on hard and has been released on hard
	else if (mouseX > hardPos.x && mouseX < hardPos.x + 600 && mouseY > hardPos.y && mouseY < hardPos.y + 200 && hardClicked)
	{
		//set the difficulty to hard
		difficulty = 2;
	}
	//if any button has been previously clicked play the release sound
	if (easyClicked || mediumClicked || hardClicked)
	{
		soundManager->PlayClickOut();
	}

	//return all clicked boolean checks back to false
	easyClicked = false;
	mediumClicked = false;
	hardClicked = false;

	//return the set difficulty
	return difficulty;
}
