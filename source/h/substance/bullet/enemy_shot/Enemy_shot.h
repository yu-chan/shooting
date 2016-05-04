#pragma once
class Enemy_shot :
	public Shot
{
public:
	Enemy_shot();
	~Enemy_shot();
	void shot_regist();
	bool collision_detection(substance);
	void move();
};

