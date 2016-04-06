// shooting/source/cpp/keyboard

#include "..\..\h\keyboard\Keyboard.h"
#include "DxLib.h"
#include "./../../h/define.h"

Keyboard::Keyboard()
{
	X = 0;
	Y = 0;
	left_right_flag = 0;
	up_down_flag = 0;
	GetHitKeyStateAll(key);
}


Keyboard::~Keyboard()
{
}

//キーが押されているかチェックする
int Keyboard::checkKey(int KEY) {
	switch (KEY) {
		case KEY_INPUT_RIGHT:
			left_right_flag = TRUE;
			X = 5;
			return TRUE;
		case KEY_INPUT_LEFT:
			left_right_flag = TRUE;
			X = -5;
			return TRUE;
		case KEY_INPUT_UP:
			up_down_flag = TRUE;
			Y = -5;
			return TRUE;
		case KEY_INPUT_DOWN:
			up_down_flag = TRUE;
			Y = 5;
			return TRUE;
	}
	left_right_flag = FALSE;
	up_down_flag = FALSE;
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
			inputKey[i]++;
		}
	}
}