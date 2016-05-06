#include "./../../h/global.h"


Fps::Fps()
{
	startTime = 0;
	count = 0;
	fps = 0;
}

bool Fps::Update() {
	//1フレーム目なら時刻を記憶
	if (count == 0) {
		startTime = GetNowCount();
	}

	//60フレーム目なら平均を計算する
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
	int tookTime = GetNowCount() - startTime;//かかった時間
	int waitTime = count * 1000 / FPS - tookTime;//待つべき時間

	//待機
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}
