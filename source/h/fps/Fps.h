#pragma once
class Fps
{
private:
	int startTime;          //測定開始時刻
	int count;              //カウンタ
	float fps;              //fps
	static const int N = 60;//平均を取るサンプル数
public:
	Fps();
	~Fps();
	bool Update();
	void Wait();
};

