// shooting/source/h/keyboard

#pragma once
//#include "./../source/h/define.h"

class Keyboard
{
private:
	int X;
	int Y;
	int LRFlag;
	int UDFlag;
public:
	unsigned int inputKey[KEYBOARD_NUM];//押されているキーフレーム数
	char key[KEYBOARD_NUM];
	Keyboard();
	~Keyboard();
	int checkKey(int);
	void updateKey();
	int getX();
	int getY();
	int getLRFlag();
	int getUDFlag();
};

