//#include "..\..\..\..\h\substance\character\player\Player.h"
#include "./../source/h/global.h"


Player::Player()
{
	key[0] = KEY_INPUT_LEFT;
	key[1] = KEY_INPUT_RIGHT;
	key[2] = KEY_INPUT_UP;
	key[3] = KEY_INPUT_DOWN;
}


Player::~Player()
{
}

void Player::move() {
	substance sub = getSub();
	sub.vx = 0;
	sub.vy = 0;
	for (int i = 0; i < 2; i++) {
		if (keyboard.checkKey(key[i]) > 0) {
			sub.vx = keyboard.getX();
		}
	}
	for (int i = 2; i < KEY_MOVE; i++) {
		if (keyboard.checkKey(key[i]) > 0) {
			sub.vy = keyboard.getY();
		}
	}

	/*if (keyboard.getLRFlag() == TRUE && keyboard.getUDFlag() == TRUE) {
		sub.vx /= ROOT2;
		sub.vy /= ROOT2;
	}*/
	sub.x += sub.vx;
	sub.y += sub.vy;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1f y=%.1f z=%.1f", sub.x, sub.y, sub.z);
}
