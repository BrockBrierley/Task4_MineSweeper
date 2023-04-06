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


int Menu::click(int mouseX, int mousY)
{
	return 0;
}
