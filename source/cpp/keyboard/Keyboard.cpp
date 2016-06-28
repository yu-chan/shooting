// shooting/source/cpp/keyboard

#include "./../../h/global.h"

Keyboard::Keyboard()
{
	LRFlag = false;
	UDFlag = false;
}

//キーが押されているかチェックする
int Keyboard::checkKey(unsigned char KEY) {
	LRFlag = false;
	UDFlag = false;
	switch (KEY) {
		case KEY_INPUT_RIGHT:
			LRFlag = true;
			break;
		case KEY_INPUT_LEFT:
			LRFlag = true;
			break;
		case KEY_INPUT_UP:
			UDFlag = true;
			break;
		case KEY_INPUT_DOWN:
			UDFlag = true;
			break;
		default:
			break;
	}
	return inputKeyFrame[KEY];
}

//キー入力の状態を更新する
int Keyboard::updateKey() {
	GetHitKeyStateAll(key);
	for (int i = 0; i < KEYBOARD_NUM; i++) {
		if (key[i] == 1) {
			inputKeyFrame[i]++;
		}
		else {
			inputKeyFrame[i] = 0;
		}
	}
	return 0;
}

bool Keyboard::getLRFlag() {
	return LRFlag;
}

bool Keyboard::getUDFlag() {
	return UDFlag;
}