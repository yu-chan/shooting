#pragma once
//#include "C:\College\syusyoku\shooting\source\h\substance\character\Character.h"
//#include "./../source/h/global.h"
class Player : public Character
{
private:
	unsigned char key[KEY_MOVE];
public:
	Player();
	~Player();
	void move();
};

