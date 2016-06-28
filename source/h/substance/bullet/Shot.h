#pragma once
class Shot : public Substance
{
public:
	Shot();
	bool collision_detection(Substance*, character*, VECTOR, int, int);
	virtual void shot_regist() = 0;
};

