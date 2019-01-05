#pragma once
class ControlPlayer
{
public:
	ControlPlayer();
	~ControlPlayer();

	bool getkeyUp();
	bool getkeyDown();
	bool getkeyLeft();
	bool getkeyRight();

	void setkeyUp(bool b);
	void setkeyDown(bool b);
	void setkeyRight(bool b);
	void setkeyLeft(bool b);

private:

	//Key State
	bool iskeyUp;
	bool iskeyDown;
	bool iskeyLeft;
	bool iskeyRight;
};