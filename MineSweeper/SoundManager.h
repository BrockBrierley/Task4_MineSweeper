#pragma once
#include "raylib.h"

static class SoundManager
{
public:
	//constructor and deconstructor
	SoundManager();
	~SoundManager();

	//Sounds players
	void PlayExplosion();
	void PlayClickIn();
	void PlayClickOut();
protected:
private:
	//method to load all sounds when the object is created
	void LoadSounds();

	//varaibles to store the loaded sounds
	Sound explosion;
	Sound clickIn;
	Sound clickOut;
};

