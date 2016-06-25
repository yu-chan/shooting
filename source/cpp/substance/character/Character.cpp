#include "./../../../h/global.h"


Character::Character()
{
}


Character::~Character()
{
}

character* Character::getCha() {
	return cha;
}

void Character::setCha(character c) {

}

void Character::mallocCha(int n) {
	cha = (character *)malloc(sizeof(character) * n);
}
