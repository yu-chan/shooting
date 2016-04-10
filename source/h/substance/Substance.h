#pragma once

class Substance {
private:
	substance sub;
public:
	Substance();
	~Substance();
	virtual void move() = 0;
	substance* getSub();
	void setSub(substance);
	void add_count();
};

