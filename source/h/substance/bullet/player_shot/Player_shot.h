#pragma once
class Player_shot :
	public Shot
{
public:
	Player_shot();
	~Player_shot();
	void shot_regist();
	//bool collision_detection();
	void move();
};

