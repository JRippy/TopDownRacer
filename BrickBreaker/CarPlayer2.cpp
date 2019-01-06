#include "pch.h"
#include "CarPlayer2.h"


CarPlayer2::CarPlayer2()
{
}

CarPlayer2::CarPlayer2(SDL_Renderer * gRenderer) :
	Car(gRenderer)
{
	resetPosition();
}


CarPlayer2::~CarPlayer2()
{
}

void CarPlayer2::keyPress(SDL_KeyboardEvent & b)
{

	// check for keypresses
	switch (b.type) {

	case SDL_KEYDOWN:
		switch (b.keysym.sym)
		{
		case SDLK_z:

			cp2.setkeyUp2(true);

			break;
		case SDLK_s:

			cp2.setkeyDown2(true);

			break;
		case SDLK_q:

			cp2.setkeyLeft2(true);
			cp2.setkeyRight2(false);

			break;
		case SDLK_d:

			cp2.setkeyRight2(true);
			cp2.setkeyLeft2(false);

			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:

		switch (b.keysym.sym)
		{
		case SDLK_z:

			cp2.setkeyUp2(false);

			break;
		case SDLK_s:

			cp2.setkeyDown2(false);

			break;
		case SDLK_q:

			cp2.setkeyLeft2(false);

			break;
		case SDLK_d:

			cp2.setkeyRight2(false);

			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}

void CarPlayer2::move(float timeStep)
{
	float carYMiddle = mPosX + (c.getCarWidth() / 2);

	if (cp2.getkeyUp2())
	{
		if (speed > -0.1)
		{
			speed += -0.01f;
		}

	}

	if (cp2.getkeyDown2())
	{
		if (speed < 0.1)
		{
			speed += 0.01f;
		}

	}

	float absolutSpeed;

	if (speed > 0)
	{
		absolutSpeed = speed;
	}
	else
	{
		absolutSpeed = fabs(speed);
	}

	if (cp2.getkeyLeft2())
	{
		if (absolutSpeed > 0.05f)
		{
			if (angle > 0)
			{
				angle -= Pi / 2 * timeStep;
			}
			else
			{
				angle = 2 * Pi;
			}
		}
	}

	if (cp2.getkeyRight2())
	{
		if (absolutSpeed > 0.05f)
		{
			if (angle < 2 * Pi)
			{
				angle += Pi / 2 * timeStep;
			}
			else
			{
				angle = 0;
			}
		}
	}

	if (!cp2.getkeyUp2() && !cp2.getkeyDown2())
	{

		//Friction
		if (speed >= 0.0001f || speed <= -0.0001f)
		{
			speed = speed * 0.99;
		}
		else
		{
			speed = 0.0f;
		}
	}

	//Move the Car left or right
	mPosX += cos(angle) * speed;
	shiftColliders();

	////If the Car went too far to the left or right
	if (mPosX + c.getCarWidth() >= c.getScreenWidth())
	{
		mPosX = c.getScreenWidth() - c.getCarWidth() - 0.2f;
		shiftColliders();
	}

	if (mPosX <= 0)
	{
		mPosX = 0.2f;
		shiftColliders();
	}

	//Move the Car up or down
	mPosY += sin(angle) * speed;
	shiftColliders();

	//If the Car went too far up or down
	if (mPosY <= 0)
	{
		mPosY = 0.2f;
		shiftColliders();
	}

	if (mPosY + c.getCarHeight() >= c.getScreenHeight())
	{
		mPosY = c.getScreenHeight() - c.getCarHeight() - 0.2f;
		shiftColliders();
	}
}

void CarPlayer2::resetPosition() {
	//Initialize the position
	int i = 0;
	int * map = c.getTileGrid();

	int j = 166;
	//while (i < c.getTileNum() && map[i] != 2)
	//{
	//	i++;
	//}

	//TODO---------------
	//int j = *((int*)map[i]);
	//if (map[i] == 2)
	if (true)
	{
		int column = j % 15;
		float columnWidth = 1 * c.getTileWidth() + c.getTileWidth() / 4;

		int row = j % 20;
		int row2 = j / 20;
		float rowHeight = 10 * c.getTileHeight() + 0 * c.getTileHeight() + c.getTileHeight() / 4;

		mPosX = columnWidth;
		mPosY = rowHeight;
	}
	else
	{
		mPosX = (float)c.getScreenWidth() / 2 - (float)c.getCarWidth();
		mPosY = (float)c.getScreenHeight() / 2 - (float)c.getCarHeight();
	}

	shiftColliders();

	printf("Reset Position : %f %f %d\n", mPosX, mPosY, j);
}
