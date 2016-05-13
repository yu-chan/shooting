#pragma once
class Shot : public Substance
{
private:
	bullet bul;
public:
	Shot();
	//~Shot();
	bool collision_detection(Substance*, VECTOR, VECTOR, int, int);
	bool collision_detection(Substance*, VECTOR, int, int);
	virtual void shot_regist() = 0;
	bullet* getBul();
};

