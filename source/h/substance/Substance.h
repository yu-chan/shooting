#pragma once
//#include "./../source/h/global.h"
class Substance {
private:
	substance sub;
	/*const unsigned char key[KEY_MOVE] = {
		KEY_INPUT_LEFT,
		KEY_INPUT_RIGHT,
		KEY_INPUT_UP,
		KEY_INPUT_DOWN
	};*/
public:
	Substance();
	~Substance();
	void move();
	substance* getSub();
	void setSub(substance);
};

