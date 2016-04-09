#pragma once

class Player : public Character
{
private:
	unsigned char key[KEY_MOVE];
public:
	Player();
	~Player();
	void move();
};

