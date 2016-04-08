// shooting/source/cpp/keyboard

//#include "..\..\h\keyboard\Keyboard.h"
//#include "DxLib.h"
//#include "./../../h/define.h"
#include "./../source/h/global.h"

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

//�L�[��������Ă��邩�`�F�b�N����
int Keyboard::checkKey(unsigned char KEY) {
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
	//return inputKeyFrame[KEY];
}

//�L�[���͂̏�Ԃ��X�V����
void Keyboard::updateKey() {
	GetHitKeyStateAll(key);
	for (int i = 0; i < KEYBOARD_NUM; i++) {
		if (key[i] != 0) {
			inputKeyFrame[i]++;
		}
		else {
			inputKeyFrame[i] = 0;
		}
	}
}

float Keyboard::getX() {
	return X;
}

float Keyboard::getY() {
	return  Y;
}

int Keyboard::getLRFlag() {
	return LRFlag;
}

int Keyboard::getUDFlag() {
	return UDFlag;
}