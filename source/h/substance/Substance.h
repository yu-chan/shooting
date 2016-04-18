#pragma once

class Substance {
private:
	substance* sub;
	int size;
public:
	Substance();
	~Substance();
	void move();
	int collision_detection(Substance);
	substance* getSub();
	void setSub(substance*);
	void mallocSub(int);
	void reallocSub(int);
	int getSize();
};

