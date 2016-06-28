#pragma once
class Shot : public Substance
{
private:
	effect* eff;
public:
	Shot();
	bool collision_detection(Substance*, character*, VECTOR, int, int);
	virtual void shot_regist() = 0;
	void effect_regist(VECTOR);
	effect* getEff();
	void mallocEff(int);
	void calc_effect();
};

