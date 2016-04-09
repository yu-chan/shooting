//#include "./../source/h/substance/Substance.h"
#include "./../source/h/global.h"


Substance::Substance()
{
	sub.x = 0.0f;
	sub.y = 0.0f;
	sub.z = 0.0f;
}


Substance::~Substance()
{
}


//à⁄ìÆêßå‰
void Substance::move() {
	/*sub.vx = 0;
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

	if (keyboard.getLRFlag() == TRUE && keyboard.getUDFlag() == TRUE) {
		sub.vx /= ROOT2;
		sub.vy /= ROOT2;
	}
	sub.x += sub.vx;
	sub.y += sub.vy;*/
}

substance* Substance::getSub() {
	return &sub;
}

void Substance::setSub(substance s) {
	sub.x = s.x;
	sub.y = s.y;
}
