#pragma once
class ControlPlayer
{
public:
	ControlPlayer();
	~ControlPlayer();

	//Player1
	bool getkeyUp();
	bool getkeyDown();
	bool getkeyLeft();
	bool getkeyRight();

	void setkeyUp(bool b);
	void setkeyDown(bool b);
	void setkeyRight(bool b);
	void setkeyLeft(bool b);

	//Player2
	bool getkeyUp2();
	bool getkeyDown2();
	bool getkeyLeft2();
	bool getkeyRight2();

	void setkeyUp2(bool b);
	void setkeyDown2(bool b);
	void setkeyRight2(bool b);
	void setkeyLeft2(bool b);

private:

	//Key State Player1
	bool iskeyUp;
	bool iskeyDown;
	bool iskeyLeft;
	bool iskeyRight;

	//Key State Player2
	bool iskeyUp2;
	bool iskeyDown2;
	bool iskeyLeft2;
	bool iskeyRight2;
};