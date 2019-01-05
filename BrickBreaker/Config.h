#pragma once
class Config
{
public:
	Config();

	static int getScreenHeight();
	static int getScreenWidth();

	static int getRacketHeight();
	static int getRacketWidth();
	static int getRacketVel();

	static int getCarHeight();
	static int getCarWidth();
	static int getCarVel();

	static int getTileHeight();
	static int getTileWidth();
	static int getTileNum();
	static int getTileNumColumn();
	static int * getTileGrid();

private:

	//Screen dimension constants
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	//The dimensions of the dot
	static const int RACKET_WIDTH = 100;
	static const int RACKET_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int RACKET_VEL = 100;

	//The dimensions of the dot
	static const int CAR_WIDTH = 20;
	static const int CAR_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int CAR_VEL = 0;

	//The dimensions of the dot
	static const int TILE_WIDTH = 40;
	static const int TILE_HEIGHT = 40;
	static const int TILE_NUM = 300;
	static const int TILE_NUMCOLUMN = 20;

};

