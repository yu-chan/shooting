#pragma once
class Vector
{
public:
	float x, y, z;
	//vec3 v1, v2;
	double rad;
	Vector();
	float dot_product_calculation(float, float, float);
	void cross_product_calculation(vec3*, vec3*);
	float getX();
	float getY();
	float getZ();
	double getRad();
};

