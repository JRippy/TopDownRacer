#include "Texture.h"
#include "Timer.h"
#include "Config.h"
#include "TilesArray.h"
#include "Car.h"
#include "CarPlayer2.h"

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#pragma once
class Game
{
public:
	Game();
	~Game();

	bool load(SDL_Renderer* gRenderer);
	bool input(SDL_Renderer* gRenderer, bool quit);
	void update();
	void draw(SDL_Renderer* gRenderer);

	void initGame();

	bool endGame(int p1, int p2);

	void free();

	void displayWinner(int p1, int p2, SDL_Color textColor, SDL_Renderer* gRenderer);

private:

	Config c;
	Texture gPromptTextTexture;
	Texture gInputTextTexture;

	//Set text color as White
	SDL_Color textColor;

	//Keeps track of time between steps
	Timer stepTimer;
	float timeStep;

	bool newGame;

	SDL_Event e;

	TilesArray tilesA;

	//The dot that will be moving around on the screen
	Car car;
	CarPlayer2 car2;

};

