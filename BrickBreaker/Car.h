#include "Timer.h"
#include "Config.h"
#include "Texture.h"
#include "ControlPlayer.h"
#include <SDL.h>
#include <math.h>

#pragma once

//A circle stucture
struct Circle
{
	int x, y;
	int r;
};

class Car
{
public:

	Car();

	Car(float x, float y);

	Config c;

	//Initializes the variables
	Car(SDL_Renderer * gRenderer);

	float getMPosX();
	float getMPosY();

	float getMVelX();
	float getMVelY();

	//load Media Car
	bool loadMediaCar(SDL_Renderer* gRenderer);
	bool isLoaded();

	//Moves the car and checks collision
	//void move(float timeStep, SDL_Rect& square);
	void move(float timeStep);

	void changeDirectionX();
	void changeDirectionY();

	//Shows the car on the screen
	void render(SDL_Renderer* gRenderer);

	//Reset position initial
	void resetPosition();

	//Gets collision circle
	Circle& getCollider();

	//Gets collision
	bool checkCollision(Circle& a, SDL_Rect& b);

	double distanceSquared(int x1, int y1, int x2, int y2);

	//Debug
	void handleEvent(SDL_Event& e, float timeStep);
	void mousePress(SDL_MouseButtonEvent& b);
	void keyPress(SDL_KeyboardEvent& b);

	void free();

private:
	bool Loaded;

	//The X and Y offsets of the Car
	float mPosX, mPosY;

	//The velocity of the Car
	float mVelX, mVelY;

	//The car angle
	float Pi = 3.141592654f;;
	float angle;

	//The car speed
	float speed;

	//Scene textures
	Texture gCarTexture;

	//Car's collision circle
	Circle mCollider;

	//Moves the collision circle relative to the Car's offset
	void shiftColliders();

	//Control player
	ControlPlayer cp;

};

