#include "pch.h"
#include "Game.h"
#include "config.h"


Game::Game()
{
}


Game::~Game()
{
}

bool Game::load(SDL_Renderer* gRenderer)
{
	textColor = { 255, 255, 255, 255 };

	newGame = true;

	tilesA = TilesArray();

	tilesA.load();

	//Calculate time step
	timeStep = stepTimer.getTicks() / 1000.f;

	car = Car(gRenderer);
	car.loadMediaCar(gRenderer);

	car2 = CarPlayer2(gRenderer);
	car2.loadMediaCar(gRenderer);

	//return car.isLoaded(); //loadMediacar(gRenderer);
	return true;
}

bool Game::input(SDL_Renderer* gRenderer, bool quit)
{
	if (!newGame)
	{
		while (SDL_PollEvent(&e) != 0)
		{

			if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			{
				initGame();
			}
		}
	}
	else
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			//Debug
			car.handleEvent(e, timeStep);
			car2.handleEvent(e, timeStep);

		}
	}
	return quit;
}

void Game::update()
{

	//Calculate time step
	timeStep = stepTimer.getTicks() / 1000.f;

	//Move for time step
	car.move(timeStep);
	car.isCollided(tilesA.isCollide(car.getCollider()));
	car2.move(timeStep);
	car2.isCollided(tilesA.isCollide(car2.getCollider()));

	//Restart step timer
	stepTimer.start();
}

void Game::draw(SDL_Renderer* gRenderer)
{
	car.render(gRenderer);
	car2.render(gRenderer);
	tilesA.render(gRenderer);
}

void Game::initGame()
{
	newGame = true;
}

bool Game::endGame(int p1, int p2)
{
	bool end = false;

	return end;
}

void Game::free()
{
	//Free loaded images
	car.free();
	car2.free();
	tilesA.free();
}

void Game::displayWinner(int p1, int p2, SDL_Color textColor, SDL_Renderer* gRenderer)
{
	std::string winnerText = "";
}
