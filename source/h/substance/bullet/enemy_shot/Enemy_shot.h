#pragma once
#include "C:\College\syusyoku\shooting\source\h\substance\bullet\Shot.h"
class Enemy_shot :
	public Shot
{
public:
	Enemy_shot();
	~Enemy_shot();
	void shot_regist();
	void move();
};

