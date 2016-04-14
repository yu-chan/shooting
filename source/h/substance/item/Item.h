#pragma once
class Item :
	public Substance
{
private:
	item ite;
public:
	Item();
	~Item();
	item* getIte();
	void move();
};

