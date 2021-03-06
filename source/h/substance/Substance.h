#pragma once

class Substance {
private:
	substance* sub;
	int size;
public:
	Substance();
	void move();
	substance* getSub();
	void setSub(substance*);
	void mallocSub(int);
	void reallocSub(int);
	int getSize();
	void rotate(float, float, float, substance*);
};

