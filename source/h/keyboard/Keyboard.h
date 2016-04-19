// shooting/source/h/keyboard

#pragma once

class Keyboard
{
private:
	bool LRFlag;
	bool UDFlag;
public:
	unsigned int inputKeyFrame[KEYBOARD_NUM];//������Ă���L�[�t���[����
	char key[KEYBOARD_NUM];
	Keyboard();
	~Keyboard();
	int checkKey(unsigned char);
	int updateKey();
	bool getLRFlag();
	bool getUDFlag();
};

