// shooting/source/h/keyboard

#pragma once
//#include "./../source/h/define.h"

class Keyboard
{
private:
	float X;
	float Y;
	int LRFlag;
	int UDFlag;
public:
	unsigned int inputKeyFrame[KEYBOARD_NUM];//押されているキーフレーム数
	char key[KEYBOARD_NUM];
	Keyboard();
	~Keyboard();
	int checkKey(unsigned char);
	int updateKey();
	float getX();
	float getY();
	int getLRFlag();
	int getUDFlag();
};

