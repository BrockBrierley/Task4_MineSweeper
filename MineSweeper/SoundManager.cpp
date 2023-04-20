#include "SoundManager.h"


SoundManager::SoundManager()
{
	LoadSounds();
}

void SoundManager::LoadSounds()
{
	std::cout << "Soundsloaded";
	explosion = LoadSound("ArtAssets/Explosion.wav");
	//clickIn = LoadSound("ArtAssets/clickIn.wav");
	//clickOut = LoadSound("ArtAssets/clickOut.wav");
}

void SoundManager::PlayExplosion()
{
	PlaySound(explosion);
}

void SoundManager::PlayClickIn()
{
	//PlaySound(clickIn);
}

void SoundManager::PlayClickOut()
{
	//PlaySound(clickOut);
}
