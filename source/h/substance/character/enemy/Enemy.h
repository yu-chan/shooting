#pragma once
class Enemy :
	public Character
{
public:
	Enemy();
	~Enemy();
	void move();
	void add_count();
};

