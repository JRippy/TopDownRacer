#include "pch.h"
#include "ControlPlayer.h"


ControlPlayer::ControlPlayer() :
iskeyUp(false),
iskeyDown(false),
iskeyLeft(false),
iskeyRight(false)
{
}


ControlPlayer::~ControlPlayer()
{
}

bool ControlPlayer::getkeyUp()
{
	return iskeyUp;
}

bool ControlPlayer::getkeyDown()
{
	return iskeyDown;
}

bool ControlPlayer::getkeyLeft()
{
	return iskeyLeft;
}

bool ControlPlayer::getkeyRight()
{
	return iskeyRight;
}

void ControlPlayer::setkeyUp(bool b)
{
	iskeyUp = b;
}

void ControlPlayer::setkeyDown(bool b)
{
	iskeyDown = b;
}

void ControlPlayer::setkeyRight(bool b)
{
	iskeyRight = b;
}

void ControlPlayer::setkeyLeft(bool b)
{
	iskeyLeft = b;
}
