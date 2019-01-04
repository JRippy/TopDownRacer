#include "Config.h"

#pragma once
class Collisions
{
public:
	Collisions();
	~Collisions();

	bool isCollided(Circle & circle);

private:

	bool isCollide = false;

	Config c;
};

