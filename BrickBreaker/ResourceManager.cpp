#include "pch.h"
#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

void ResourceManager::load()
{
}

int * ResourceManager::getCar(SDL_Renderer* gRenderer)
{
	//Load Car texture
	if (!gCarTexture.loadFromFile("pixelart-cars.png", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		//Loaded = false;
	}

	return nullptr;
}

int * ResourceManager::getRoad(SDL_Renderer* gRenderer)
{
	//Load Car texture
	if (!gRoadTexture.loadFromFile("Road.png", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		//Loaded = false;
	}

	return nullptr;
}

int * ResourceManager::getBlock(SDL_Renderer* gRenderer)
{
	//Load Car texture
	if (!gBLockTexture.loadFromFile("Rock.png", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		//Loaded = false;
	}

	return nullptr;
}
