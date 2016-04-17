#include "./../../h/global.h"


Substance::Substance()
{
	size = 0;
	sub.x = 0.0f;
	sub.y = 0.0f;
	sub.z = 0.0f;
	sub.count = 0;
	sub.vx = 0.1f;
	//(*s).vx = 0.1f;
}


Substance::~Substance()
{
}

substance* Substance::getSub() {
	return &sub;
}

void Substance::setSub(substance s) {
	sub.x = s.x;
	sub.y = s.y;
}


void Substance::add_count() {
	sub.count++;
}

substance* Substance::getS() {
	return s;
}

void Substance::setS(substance* ss) {
	s = ss;
}

void Substance::mallocS(int n) {
	size = n;
	s = (substance *)malloc(sizeof(substance) * size);
}

void Substance::reallocS(int n) {
	if (size >= n) { return; }
	size = n;
	s = (substance *)realloc(s, size);
}

int Substance::getSize() {
	return size;
}