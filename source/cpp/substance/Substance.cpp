#include "./../../h/global.h"


Substance::Substance()
{
	sub.x = 0.0f;
	sub.y = 0.0f;
	sub.z = 0.0f;
	sub.count = 0;
	sub.vx = 0.1f;
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