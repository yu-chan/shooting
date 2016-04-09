#pragma once
class Shot : public Substance
{
private:
	bullet bul;
public:
	Shot();
	~Shot();
	virtual void shot_regist() = 0;
	bullet* getBul();
};

