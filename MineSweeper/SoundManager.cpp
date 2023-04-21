#include "SoundManager.h"

/// <summary>
/// sound manager constructor, loads all the sounds when initialised
/// </summary>
SoundManager::SoundManager()
{
	LoadSounds();
}

/// <summary>
/// deconstructor to unload the sounds
/// </summary>
SoundManager::~SoundManager()
{
	UnloadSound(explosion);
	UnloadSound(clickIn);
	UnloadSound(clickOut);
}

/// <summary>
/// method called by the constructor to load all the wav files as sounds
/// </summary>
void SoundManager::LoadSounds()
{
	//load the death explosion sound
	explosion = LoadSound("ArtAssets/Explosion.wav");
	
	//load the mouse click button sounds
	clickIn = LoadSound("ArtAssets/clickIn.wav");
	clickOut = LoadSound("ArtAssets/clickOut.wav");
}

/// <summary>
/// Plays the loaded explosion sound
/// </summary>
void SoundManager::PlayExplosion()
{
	PlaySound(explosion);
}

/// <summary>
/// PLays the loadded click in sound
/// </summary>
void SoundManager::PlayClickIn()
{
	PlaySound(clickIn);
}

//plays the loaded click out sound
void SoundManager::PlayClickOut()
{
	PlaySound(clickOut);
}
