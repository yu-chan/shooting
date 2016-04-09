// shooting/source/cpp/keyboard

//#include "..\..\h\keyboard\Keyboard.h"
//#include "DxLib.h"
//#include "./../../h/define.h"
#include "./../source/h/global.h"

Keyboard::Keyboard()
{
	LRFlag = FALSE;
	UDFlag = FALSE;
}


Keyboard::~Keyboard()
{
	//delete[] inputKey;
	//delete[] key;
}

//キーが押されているかチェックする
int Keyboard::checkKey(unsigned char KEY) {
	LRFlag = FALSE;
	UDFlag = FALSE;
	switch (KEY) {
		case KEY_INPUT_RIGHT:
			LRFlag = TRUE;
			break;
		case KEY_INPUT_LEFT:
			LRFlag = TRUE;
			break;
		case KEY_INPUT_UP:
			UDFlag = TRUE;
			break;
		case KEY_INPUT_DOWN:
			UDFlag = TRUE;
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

int Keyboard::getLRFlag() {
	return LRFlag;
}

int Keyboard::getUDFlag() {
	return UDFlag;
}