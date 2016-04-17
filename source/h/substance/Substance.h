#pragma once

class Substance {
private:
	substance sub;
	substance* s;
	int size;
public:
	Substance();
	~Substance();
	void move();
	int collision_detection(Substance);
	substance* getSub();
	void setSub(substance);
	void add_count();
	substance* getS();
	void setS(substance*);
	void mallocS(int);
	void reallocS(int);
};

