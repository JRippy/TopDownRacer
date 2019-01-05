#include "Texture.h"
#pragma once

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void load();

	int * getCar(SDL_Renderer* gRenderer);

	int * getRoad(SDL_Renderer* gRenderer);

	int * getBlock(SDL_Renderer* gRenderer);

private :

	Texture gCarTexture;

	Texture gRoadTexture;

	Texture gBLockTexture;
};

