#pragma once

class Substance {
private:
	substance sub;
public:
	Substance();
	~Substance();
	void move();
	substance* getSub();
	void setSub(substance);
};

