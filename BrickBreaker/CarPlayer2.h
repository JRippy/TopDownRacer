#pragma once
#include "Car.h"
class CarPlayer2 :
	public Car
{
public:
	CarPlayer2();
	CarPlayer2(SDL_Renderer * gRenderer);
	~CarPlayer2();

	void keyPress(SDL_KeyboardEvent& b);

	void move(float timeStep);

	void resetPosition();

private :
	//The X and Y offsets of the Car
	float mPosX, mPosY;

	//The velocity of the Car
	float mVelX, mVelY;

	//Control player2
	ControlPlayer cp2;
};

