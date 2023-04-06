#include "Menu.h"

Menu::Menu()
{
	//load images
	Title = LoadTexture("ArtAssets/title.png");
	easyUnpressed = LoadTexture("ArtAssets/EasyUnpressed.png");
	easyPressed = LoadTexture("ArtAssets/EasyPressed.png");
	mediumUnpressed = LoadTexture("ArtAssets/MediumUnpressed.png");
	mediumPressed = LoadTexture("ArtAssets/MediumPressed.png");
	hardUnpressed = LoadTexture("ArtAssets/HardUnpressed.png");
	hardPressed = LoadTexture("ArtAssets/HardPressed.png");
}

Menu::~Menu()
{
}

void Menu::Draw()
{
	DrawTextureEx(Title, titlePos, 0.0f, 1.0f, WHITE);
	if (easyClicked)
	{
		DrawTextureEx(easyPressed, easyPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(easyUnpressed, easyPos, 0.0f, 1.0f, WHITE);
	}

	if (mediumClicked)
	{
		DrawTextureEx(mediumPressed, mediumPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(mediumUnpressed, mediumPos, 0.0f, 1.0f, WHITE);
	}
	if (hardClicked)
	{
		DrawTextureEx(hardPressed, hardPos, 0.0f, 1.0f, WHITE);
	}
	else
	{
		DrawTextureEx(hardUnpressed, hardPos, 0.0f, 1.0f, WHITE);
	}

}


void Menu::click(int mouseX, int mouseY)
{
	if (mouseX > easyPos.x && mouseX < easyPos.x + 600 && mouseY > easyPos.y && mouseY < easyPos.y +200)
	{
		easyClicked = true;
	}
	else if (mouseX > mediumPos.x && mouseX < mediumPos.x + 600 && mouseY > mediumPos.y && mouseY < mediumPos.y + 200)
	{
		mediumClicked = true;
	}
	else if (mouseX > hardPos.x && mouseX < hardPos.x + 600 && mouseY > hardPos.y && mouseY < hardPos.y + 200)
	{
		hardClicked = true;
	}
}

int Menu::release(int mouseX, int mouseY)
{
	int difficulty = -1;
	if (mouseX > easyPos.x && mouseX < easyPos.x + 600 && mouseY > easyPos.y && mouseY < easyPos.y + 200 && easyClicked)
	{
		easyClicked = true;
		difficulty = 0;
	}
	else if (mouseX > mediumPos.x && mouseX < mediumPos.x + 600 && mouseY > mediumPos.y && mouseY < mediumPos.y + 200 && mediumClicked)
	{
		mediumClicked = true;
		difficulty = 1;
	}
	else if (mouseX > hardPos.x && mouseX < hardPos.x + 600 && mouseY > hardPos.y && mouseY < hardPos.y + 200 && hardClicked)
	{
		hardClicked = true;
		difficulty = 2;
	}
	easyClicked = false;
	mediumClicked = false;
	hardClicked = false;
	return difficulty;
}
