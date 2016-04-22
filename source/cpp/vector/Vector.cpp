#include "./../../h/global.h"


Vector::Vector()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

float Vector::dot_product_calculation(float x, float y, float z) {
	return this->x * x + this->y * y + this->z * z;
}

void Vector::cross_product_calculation(vec3 *v1, vec3 *v2) {
	x = v1->y * v2->z - v1->z * v2->y;
	y = v1->z * v2->x - v1->x * v2->z;
	z = v1->x * v2->y - v1->y * v2->x;
}

float Vector::getX() {
	return x;
}

float Vector::getY() {
	return y;
}

float Vector::getZ() {
	return z;
}

double Vector::getRad() {
	return rad;
}