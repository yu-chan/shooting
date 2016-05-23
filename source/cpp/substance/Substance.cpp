#include "./../../h/global.h"

static const float ROTATE_SPEED = DX_PI_F / 90; //回転スピード

Substance::Substance()
{
	size = 0;
}

substance* Substance::getSub() {
	return sub;
}

void Substance::setSub(substance* s) {
	sub = s;
}

void Substance::mallocSub(int n) {
	size = n;
	sub = (substance *)malloc(sizeof(substance) * size);
}

void Substance::reallocSub(int n) {
	if (size >= n) { return; }
	size = n;
	sub = (substance *)realloc(sub, size);
}

int Substance::getSize() {
	return size;
}

void Substance::rotate(float angX, float angY, float angZ, substance* s) {
}