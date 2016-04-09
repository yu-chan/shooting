// shooting/source/cpp/mainの中

#define GLOBAL_INSTANCE
//#include "./../../../DxLib_VC/DxLib.h"

#include <windows.h>

#include "DxLib.h"
#include "./../source/h/global.h"

//実行中にエラーが出たら、ゲームを強制終了する関数
int Process_Screen() {
	//プロセス処理にエラーが出たなら、-1を返す
	if (ProcessMessage() != 0) { 
		return -1;  
	}
	//画面クリア処理がエラーなら、-1を返す
	if (ClearDrawScreen() != 0) {
		return -1;
	}

	keyboard.updateKey();

	//エラーが出てないなら、正常なので0を返す
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウモードに設定
	ChangeWindowMode(TRUE);


	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0) {
		//初期化に失敗したら終了
		return -1;
	}

	//裏画面化
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) {
		//失敗したら終了
		return -1;
	}


	//最初に１度だけデータをロードする
	load_3DModel();

	//ここに関数を置く
	while (Process_Screen() == 0) {
		//ESCきーを押せば強制終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		player.move();

		//座標をセット
		setCamera();
		setPosition_Player();

		//描画
		draw();

		//裏画面反映
		ScreenFlip();
	}

	//エラー処理したい時にこれを使おう
	//OutputDebugStringW(L"とりあえず\n");

	// ＤＸライブラリの後始末
	DxLib_End();

	//メモリの開放
	keyboard.~Keyboard();

	// ソフトの終了
	return 0;
}