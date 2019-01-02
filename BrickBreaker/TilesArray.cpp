#include "pch.h"
#include "TilesArray.h"


TilesArray::TilesArray()
{
	vTiles.reserve(c.getTileNum());
	initTiles();
}

void TilesArray::load()
{
	int indice = 0;
	int TilesColNum = 0;
	int * map = c.getTileGrid();

	for (size_t j = 0; j < 600; j += c.getTileWidth())
	{	
		for (size_t i = 0; i < 800; i += c.getTileHeight())
		{
			//int indice = i / c.getTileHeight() + TilesColNum * j / c.getTileWidth();
			
			Tile b = Tile(i, j, i + TilesColNum * j, indice, map[indice]);
			vTiles.push_back(b);
			TilesColNum++;
			indice++;
		}
		TilesColNum = 0;
	}

	//Remove 3 first line
	//for (size_t i = 0; i < 30; i++)
	//{
	//	desactivateBrick(i);
	//}
}

void TilesArray::render(SDL_Renderer * gRenderer)
{
	for (int TilesNum = 0; TilesNum < c.getTileNum(); TilesNum++)
	{

		if (vTiles[TilesNum].visible == true) {

			SDL_Rect racket;

			racket.x = vTiles[TilesNum].posBX;
			racket.y = vTiles[TilesNum].posBY;
			racket.w = c.getTileWidth() - 2 ;
			racket.h = c.getTileHeight()- 2;

			//Render racket
			SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(gRenderer, &racket);
			SDL_RenderFillRect(gRenderer, &racket);

			//Show the Racket
			gTileTexture.render(racket.x, racket.y, gRenderer);

		}
	}
}

bool TilesArray::isCollide(Circle& circle)
{
	if (circle.y < (c.getScreenHeight() / 2 - 20))
	{

		int dotTilex = circle.x / c.getTileWidth();
		int dotTiley = circle.y / c.getTileHeight();

		int numB = dotTilex + 10 * dotTiley;


		//Test Collide with refact----------------------------------
		SDL_Rect test;

		test.x = dotTilex * 80;
		test.y = dotTiley * 20;
		test.w = c.getTileWidth() - 2;
		test.h = c.getTileHeight() - 2;

		//printf("Bool collide %d/n", isCollideBrick(circle, test));
		//-------------------------------------------------------------

		if (numB < c.getTileNum())
		{
			if (isActiv(numB) && isCollideTile(circle, test))
			{

				if (previewColumn == dotTilex)
				{
					if (previewRow != dotTiley)
					{
						changeY = true;
					}
				}
				else
				{
					if (previewRow == dotTiley)
					{
						changeX = true;
					}
					else
					{
						changeY = true;
						changeX = true;
					}
				}

				desactivateTile(numB);
			}

			previewColumn = dotTilex;
			previewRow = dotTiley;

			return true;
		}

		previewColumn = dotTilex;
		previewRow = dotTiley;

		return false;
	}

	return false;
}

bool TilesArray::isCollideTile(Circle& a, SDL_Rect& b)
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

double TilesArray::distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
}

void TilesArray::activateTile(int i)
{
	activeTile++;
	desactiveTile--;
	Tile& b = vTiles[i];
	b.visible = true;
}

void TilesArray::desactivateTile(int i)
{
	Tile& b = vTiles[i];
	b.visible =  false;
	activeTile--;
	desactiveTile++;

	if (activeTile <= 0 || desactiveTile >= c.getTileNum())
	{
		reinitTiles();
	}
}

bool TilesArray::isActiv(int k)
{
	return vTiles[k].visible;
}

bool TilesArray::changeVelX()
{
	return changeX;
}

bool TilesArray::changeVelY()
{
	return changeY;
}

void TilesArray::reInitBoolVel()
{
	changeX = false;
	changeY = false;
}

void TilesArray::initTiles()
{
	activeTile = c.getTileNum();
	desactiveTile = 0;
	previewColumn = -1;
	previewRow = -1;
	changeX = false;
	changeY = false;
}

void TilesArray::reinitTiles()
{
	for (int i = 0; i < c.getTileNum(); i++)
	{
		activateTile(i);
	}

	initTiles();
}
