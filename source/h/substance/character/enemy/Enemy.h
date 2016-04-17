#pragma once
class Enemy :
	public Character
{
public:
	Enemy();
	~Enemy();
	void move();
	void enemy_regist();
};

