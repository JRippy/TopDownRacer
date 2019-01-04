#include "pch.h"
#include "Collisions.h"
#include "TilesArray.h"


Collisions::Collisions()
{
}


Collisions::~Collisions()
{
}

bool Collisions::isCollided(Circle & circle)
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

			return isCollide;
		}

		previewColumn = dotTilex;
		previewRow = dotTiley;

		return isCollide;
	}

	return isCollide;
}
