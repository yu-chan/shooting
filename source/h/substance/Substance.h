#pragma once

class Substance {
private:
	substance sub;
public:
	Substance();
	~Substance();
	void move();
	int collision_detection(Substance);
	substance* getSub();
	void setSub(substance);
	void add_count();
};

