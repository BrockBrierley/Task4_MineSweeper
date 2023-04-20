#include "Menu.h"

Menu::Menu(ImageManager* iM, SoundManager* sm)
{
	imageManager = iM;
	soundManager = sm;
}

Menu::~Menu()
{

}

void Menu::Draw()
{
	DrawTextureEx(imageManager->GetTitle(), titlePos, 0.0f, 1.0f, WHITE);
	if (easyClicked)
	{
		DrawTextureEx(imageManager->GetEasy(true), easyPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(imageManager->GetEasy(false), easyPos, 0.0f, 1.0f, WHITE);
	}

	if (mediumClicked)
	{
		DrawTextureEx(imageManager->GetMed(true), mediumPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(imageManager->GetMed(false), mediumPos, 0.0f, 1.0f, WHITE);
	}
	if (hardClicked)
	{
		DrawTextureEx(imageManager->GetHard(true), hardPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(imageManager->GetHard(false), hardPos, 0.0f, 1.0f, WHITE);
	}

}


void Menu::click(int mouseX, int mouseY)
{
	if (mouseX > easyPos.x && mouseX < easyPos.x + 600 && mouseY > easyPos.y && mouseY < easyPos.y +200)
	{
		soundManager->PlayClickIn();
		easyClicked = true;
	}
	else if (mouseX > mediumPos.x && mouseX < mediumPos.x + 600 && mouseY > mediumPos.y && mouseY < mediumPos.y + 200)
	{
		soundManager->PlayClickIn();
		mediumClicked = true;
	}
	else if (mouseX > hardPos.x && mouseX < hardPos.x + 600 && mouseY > hardPos.y && mouseY < hardPos.y + 200)
	{
		soundManager->PlayClickIn();
		hardClicked = true;
	}
}

int Menu::release(int mouseX, int mouseY)
{
	int difficulty = -1;
	if (mouseX > easyPos.x && mouseX < easyPos.x + 600 && mouseY > easyPos.y && mouseY < easyPos.y + 200 && easyClicked)
	{
		difficulty = 0;
	}
	else if (mouseX > mediumPos.x && mouseX < mediumPos.x + 600 && mouseY > mediumPos.y && mouseY < mediumPos.y + 200 && mediumClicked)
	{
		difficulty = 1;
	}
	else if (mouseX > hardPos.x && mouseX < hardPos.x + 600 && mouseY > hardPos.y && mouseY < hardPos.y + 200 && hardClicked)
	{
		difficulty = 2;
	}
	if (easyClicked || mediumClicked || hardClicked)
	{
		soundManager->PlayClickOut();
	}

	easyClicked = false;
	mediumClicked = false;
	hardClicked = false;
	return difficulty;
}
