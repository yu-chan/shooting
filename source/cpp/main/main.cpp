// shooting/source/cpp/mainの中

#define GLOBAL_INSTANCE
#include "./../../../DxLib_VC/DxLib.h"

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

	//エラーが出てないなら、正常なので0を返す
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウモードに設定
	ChangeWindowMode(TRUE);


	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0)
	{
		//初期化に失敗したら終了
		return -1;
	}

	//裏画面化
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) {
		//失敗したら終了
		return -1;
	}

	//ここに関数を置く
	while (Process_Screen() == 0) {
		//ESCきーを押せば強制終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		//裏画面反映
		ScreenFlip();
	}

	// ３Ｄ空間上に線分を描画する
	//DrawLine3D(VGet(100.0f, 100.0f, 0.0f), VGet(300.0f, 200.0f, 0.0f), GetColor(255, 255, 255));

	// キー入力待ちをする
	WaitKey();

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}