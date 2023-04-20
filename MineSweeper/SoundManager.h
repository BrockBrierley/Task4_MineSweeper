#pragma once
#include "raylib.h"

static class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void PlayExplosion();
	void PlayClickIn();
	void PlayClickOut();
protected:
private:
	void LoadSounds();
	Sound explosion;
	Sound clickIn;
	Sound clickOut;
};

