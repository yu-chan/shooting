// shooting/source/h/keyboard

#pragma once
#include "./../source/h/define.h"

class Keyboard
{
private:
	int X;
	int Y;
	int left_right_flag;
	int up_down_flag;
public:
	int inputKey[KEYBOARD_NUM];//押されているキーフレーム数
	char key[KEYBOARD_NUM];
	Keyboard();
	~Keyboard();
	int checkKey(int);
	void updateKey();
};

