#pragma once
class Fps
{
private:
	int startTime;          //����J�n����
	int count;              //�J�E���^
	float fps;              //fps
	static const int N = 60;//���ς����T���v����
public:
	Fps();
	~Fps();
	bool Update();
	void Wait();
};

