#include "./../../h/global.h"


Fps::Fps()
{
	startTime = 0;
	count = 0;
	fps = 0;
}

bool Fps::Update() {
	//1�t���[���ڂȂ玞�����L��
	if (count == 0) {
		startTime = GetNowCount();
	}

	//60�t���[���ڂȂ畽�ς��v�Z����
	if (count == N) {
		int t = GetNowCount();
		fps = 1000.f / ((t - startTime) / (float)FPS);
		count = 0;
		startTime = t;
	}
	count++;
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", fps);
	return true;
}

void Fps::Wait() {
	int tookTime = GetNowCount() - startTime;//������������
	int waitTime = count * 1000 / FPS - tookTime;//�҂ׂ�����

	//�ҋ@
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}
