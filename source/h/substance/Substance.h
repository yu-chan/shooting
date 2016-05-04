#pragma once

class Substance {
private:
	substance* sub;
	int size;
public:
	Substance();
	void move();
	//bool collision_detection(substance);
	substance* getSub();
	void setSub(substance*);
	void mallocSub(int);
	void reallocSub(int);
	int getSize();
};

