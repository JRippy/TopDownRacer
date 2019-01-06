#include "pch.h"
#include "ControlPlayer.h"


ControlPlayer::ControlPlayer() :
	iskeyUp(false),
	iskeyDown(false),
	iskeyLeft(false),
	iskeyRight(false),
	iskeyUp2(false),
	iskeyDown2(false),
	iskeyLeft2(false),
	iskeyRight2(false)
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

bool ControlPlayer::getkeyUp2()
{
	return iskeyUp2;
}

bool ControlPlayer::getkeyDown2()
{
	return iskeyDown2;
}

bool ControlPlayer::getkeyLeft2()
{
	return iskeyLeft2;
}

bool ControlPlayer::getkeyRight2()
{
	return iskeyRight2;
}

void ControlPlayer::setkeyUp2(bool b)
{
	iskeyUp2 = b;
}

void ControlPlayer::setkeyDown2(bool b)
{
	iskeyDown2 = b;
}

void ControlPlayer::setkeyRight2(bool b)
{
	iskeyRight2 = b;
}

void ControlPlayer::setkeyLeft2(bool b)
{
	iskeyLeft2 = b;
}
