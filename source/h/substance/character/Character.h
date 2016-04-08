#pragma once
//#include "C:\College\syusyoku\shooting\source\h\substance\Substance.h"
//#include "./../source/h/global.h"
class Character : public Substance {
private:
	character cha;
public:
	Character();
	~Character();
	character getCha();
	void setCha();
};

