#pragma once
//#include "C:\College\syusyoku\shooting\source\h\substance\character\Character.h"
//#include "./../source/h/global.h"
class Player : public Character
{
private:
	unsigned char key[KEY_MOVE]; /*= {
		KEY_INPUT_LEFT,
		KEY_INPUT_RIGHT,
		KEY_INPUT_UP,
		KEY_INPUT_DOWN
	};*/
public:
	Player();
	~Player();
	void move();
};

