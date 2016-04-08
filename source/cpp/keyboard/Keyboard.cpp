// shooting/source/cpp/keyboard

#include "..\..\h\keyboard\Keyboard.h"
#include "DxLib.h"
#include "./../../h/define.h"

Keyboard::Keyboard()
{
	X = 0;
	Y = 0;
	LRFlag = 0;
	UDFlag = 0;
	GetHitKeyStateAll(key);
}


Keyboard::~Keyboard()
{
	//delete[] inputKey;
	//delete[] key;
}

//キーが押されているかチェックする
int Keyboard::checkKey(int KEY) {
	switch (KEY) {
		case KEY_INPUT_RIGHT:
			LRFlag = TRUE;
			X = 5;
			return TRUE;
		case KEY_INPUT_LEFT:
			LRFlag = TRUE;
			X = -5;
			return TRUE;
		case KEY_INPUT_UP:
			UDFlag = TRUE;
			Y = -5;
			return TRUE;
		case KEY_INPUT_DOWN:
			UDFlag = TRUE;
			Y = 5;
			return TRUE;
	}
	LRFlag = FALSE;
	UDFlag = FALSE;
	X = 0;
	Y = 0;
	return FALSE;
}

//キー入力の状態を更新する
void Keyboard::updateKey() {
	GetHitKeyStateAll(key);
	for (int i = 0; i < KEYBOARD_NUM; i++) {
		if (key[i] != 0) {
			inputKey[i]++;
		}
		else {
			inputKey[i] = 0;
		}
	}
}

int Keyboard::getX() {
	return X;
}

int Keyboard::getY() {
	return  Y;
}

int Keyboard::getLRFlag() {
	return LRFlag;
}

int Keyboard::getUDFlag() {
	return UDFlag;
}