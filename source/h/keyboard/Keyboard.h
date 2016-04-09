// shooting/source/h/keyboard

#pragma once
//#include "./../source/h/define.h"

class Keyboard
{
private:
	int LRFlag;
	int UDFlag;
public:
	unsigned int inputKeyFrame[KEYBOARD_NUM];//������Ă���L�[�t���[����
	char key[KEYBOARD_NUM];
	Keyboard();
	~Keyboard();
	int checkKey(unsigned char);
	int updateKey();
	int getLRFlag();
	int getUDFlag();
};

