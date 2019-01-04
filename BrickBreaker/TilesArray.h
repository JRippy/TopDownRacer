#pragma once
#include "Car.h"
#include "Racket.h"
#include "Tile.h"
#include "Config.h"
#include <vector>

class TilesArray : public Racket
{
public:

	Config c;

	TilesArray();

	void load();

	//Shows Tiles on the screen
	void render(SDL_Renderer* gRenderer);

	bool isCollide(Circle& c);

	bool isCollideTile(Circle& a, SDL_Rect& b);

	double distanceSquared(int x1, int y1, int x2, int y2);

	void activateTile(int i);

	void desactivateTile(int j);

	bool isActiv(int k);

	void initTiles();
	void reinitTiles();

private:

	std::vector<Tile> vTiles;
	int activeTile;
	int desactiveTile;

	//Texture
	Texture gTileTexture;

	int previewColumn;
	int previewRow;
};