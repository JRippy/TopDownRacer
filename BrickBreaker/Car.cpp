#include "pch.h"
#include "Car.h"


Car::Car() :
	speed((float)c.getCarVel())
{
	angle = Pi / 2;

	resetPosition();

}

Car::Car(float x, float y) :
	speed((float)c.getCarVel())
{
	mPosX = x;
	mPosY = y;
	angle = Pi / 2;
}

Car::Car(SDL_Renderer * gRenderer) :
	speed((float)c.getCarVel()),
	Loaded(false)
{
	angle = Pi / 2;

	resetPosition();

	Loaded = loadMediaCar(gRenderer);

	//Set collision circle size
	mCollider.r = c.getCarWidth() / 2;

	//Move collider relative to the circle
	shiftColliders();
}

float Car::getMPosX()
{
	return mPosX;
}

float Car::getMPosY()
{
	return mPosY;
}

float Car::getMVelX()
{
	return mVelX;
}

float Car::getMVelY()
{
	return mVelY;
}

bool Car::loadMediaCar(SDL_Renderer * gRenderer)
{
	//Loading success flag
	Loaded = true;

	//Load Car texture
	if (!gCarTexture.loadFromFile("dot.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		Loaded = false;
	}

	return Loaded;
}

bool Car::isLoaded()
{
	return Loaded;
}

//void Car::move(float timeStep, SDL_Rect& square)
//{
//	float CarYMiddle = mPosX + (c.getCarWidth() / 2);
//
//	//Move the Car left or right
//	mPosX += mVelX * timeStep;
//	shiftColliders();
//
//	////If the Car went too far to the left or right
//	if (mPosX + c.getCarWidth() >= c.getScreenWidth() || mPosX <= 0)
//	{
//		mVelX = -mVelX;
//		shiftColliders();
//		//resetPosition();
//	}
//
//	//Move the Car up or down
//	mPosY += mVelY * timeStep;
//	shiftColliders();
//
//	//If the Car went too far up or down
//	if (mPosY <= 0)
//	{
//		mVelY = -mVelY;
//		shiftColliders();
//	}
//
//	if (mPosY + c.getCarHeight() >= c.getScreenHeight())
//	{
//		resetPosition();
//	}
//
//	if (checkCollision(mCollider, square))
//	{
//		if (mVelY != 0.0f)
//		{
//			if (mPosY + (c.getCarHeight() / 2) <= square.y)
//			{
//				const float Pi = 3.141592654f;
//				float MAXBOUNCEANGLE = 8 * Pi / 12;
//				int intersect = mPosX - (square.x + (c.getRacketWidth() / 2));
//
//				float relativeIntersectX = (mPosX + (c.getRacketWidth() / 2)) - CarYMiddle;
//				float normalizedRelativeIntersectionX = (relativeIntersectX / (c.getRacketWidth() / 2));
//				float bounceAngle = normalizedRelativeIntersectionX * MAXBOUNCEANGLE;
//
//				if (intersect < 0) {
//					mVelX = -mVelX;
//				}
//
//				mVelY = -mVelY * sin(bounceAngle);
//				mPosY -= 0.01;
//
//				//printf("Paddle mVelX : %f + mVelY : %f \n", mVelX, mVelY);
//				//printf("\nVitesse Y : %f\n", -mVelY);
//				//printf("New Vitesse Y : %f\n", mVelY * sin(bounceAngle));
//				//printf("bounclAngle : %f\n", bounceAngle);
//				//printf("Sin bounclAngle : %f\n", sin(bounceAngle));
//				//printf("Intersect : %d\n", intersect);
//				//printf("Relative bounclAngle : %f\n\n", normalizedRelativeIntersectionX);
//			}
//			else
//			{
//				mVelX = -mVelX;
//			}
//
//		}
//		else
//		{
//			mVelX = -mVelX;
//			mVelY += 10;
//		}
//
//	}
//}


void Car::move(float timeStep)
{
	float carYMiddle = mPosX + (c.getCarWidth() / 2);
	
	if (cp.getkeyUp())
	{
		if (speed > -0.1)
		{
			speed += -0.01f;
		}

	}

	if (cp.getkeyDown())
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

	if (cp.getkeyLeft())
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

	if (cp.getkeyRight())
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

	if(!cp.getkeyUp() && !cp.getkeyDown())
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

	if ( mPosY + c.getCarHeight() >= c.getScreenHeight())
	{
		mPosY = c.getScreenHeight() - c.getCarHeight() - 0.2f;
		shiftColliders();
	}
}

void Car::isCollided(bool b)
{
	if (b)
	{
		speed += -speed * 0.5;
	}
}

void Car::changeDirectionX()
{
	mVelX = -mVelX;
}

void Car::changeDirectionY()
{
	mVelY = -mVelY;
}

void Car::render(SDL_Renderer* gRenderer)
{
	//Load Car texture
	//if (!gCarTexture.loadFromFile("dot.bmp", gRenderer))
	//{
	//	printf("Failed to load dot texture!\n");
	//}

	//Show the Car
	gCarTexture.render((int)mPosX, (int)mPosY, gRenderer);
}

void Car::resetPosition() {
	//Initialize the position
	int i = 0;
	int * map = c.getTileGrid();
	
	int j = 165;
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

	printf("Reset Position 1 : %f %f %d\n", mPosX, mPosY, j);
}

Circle & Car::getCollider()
{
	return mCollider;
}

void Car::shiftColliders()
{
	//Align collider to center of Car
	mCollider.x = (int)mPosX + (c.getCarHeight() / 2);
	mCollider.y = (int)mPosY + (c.getCarWidth() / 2);
}


bool Car::checkCollision(Circle& a, SDL_Rect& b)
{
	//Closest point on collision box
	int cX, cY;

	//Find closest x offset
	if (a.x < b.x)
	{
		cX = b.x;
	}
	else if (a.x > b.x + b.w)
	{
		cX = b.x + b.w;
	}
	else
	{
		cX = a.x;
	}

	//Find closest y offset
	if (a.y < b.y)
	{
		cY = b.y;
	}
	else if (a.y > b.y + b.h)
	{
		cY = b.y + b.h;
	}
	else
	{
		cY = a.y;
	}

	//If the closest point is inside the circle
	if (distanceSquared(a.x, a.y, cX, cY) <= a.r * a.r)
	{
		//This box and the circle have collided
		return true;
	}

	//If the shapes have not collided
	return false;
}


double Car::distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
}

void Car::handleEvent(SDL_Event & e, float timeStep)
{
	//If a key was pressed
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		mousePress(e.button);
	}

	keyPress(e.key);
}

void Car::mousePress(SDL_MouseButtonEvent& b) {
	if (b.button == SDL_BUTTON_LEFT) {
		//handle a left-click
		int x, y;
		SDL_GetMouseState(&x, &y);

		mPosX = (float)x;
		mPosY = (float)y;

		if (x <= 0)
		{
			mPosX = 0;
		}
		//else if (mPosX > c.getScreenWidth() - (c.getRacketWidth() / 2) || x > c.getScreenWidth() - (c.getRacketWidth() / 2))
		//{
		//	mPosX = (float)c.getScreenWidth() - (float)c.getRacketWidth() / 2;
		//}
		else if (x < c.getScreenWidth() && x > 0)
		{
			//Adjust position
			mPosX = (float)x - c.getCarWidth() / 2;
			//move(timeStep);
		}
	}
}

void Car::keyPress(SDL_KeyboardEvent & b)
{
	
	// check for keypresses
	switch (b.type) {
		
	case SDL_KEYDOWN:
		switch (b.keysym.sym)
		{
		case SDLK_UP:

			cp.setkeyUp(true);

			break;
		case SDLK_DOWN:
			
			cp.setkeyDown(true);

			break;
		case SDLK_LEFT:

			cp.setkeyLeft(true);
			cp.setkeyRight(false);

			break;
		case SDLK_RIGHT:
			
			cp.setkeyRight(true);
			cp.setkeyLeft(false);

			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		
		switch (b.keysym.sym)
		{
		case SDLK_UP:

			cp.setkeyUp(false);

			break;
		case SDLK_DOWN:
			
			cp.setkeyDown(false);

			break;
		case SDLK_LEFT:

			cp.setkeyLeft(false);

			break;
		case SDLK_RIGHT:

			cp.setkeyRight(false);

			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}

void Car::free()
{
	gCarTexture.free();
}
