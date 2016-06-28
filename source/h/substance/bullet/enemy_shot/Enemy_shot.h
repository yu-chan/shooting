#pragma once
class Enemy_shot :
	public Shot
{
public:
	Enemy_shot();
	~Enemy_shot();
	void shot_regist();
	void move();
};

