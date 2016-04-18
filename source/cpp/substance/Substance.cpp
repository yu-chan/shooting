#include "./../../h/global.h"


Substance::Substance()
{
	size = 0;
}


Substance::~Substance()
{
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