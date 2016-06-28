// shooting/source/cpp/drawの中

/*
  画像の描画
*/
#include "./../../h/global.h" 

//文字の輝度
static int char_br = 0;
static int charClearOver = 0;
int i = 2;

//カメラの描画範囲を決める
void setCamera() {
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);						 
	SetCameraPositionAndTarget_UpVecY(camera_pos, camera_look);
}

//自機の描画
void draw_Player() {
	substance *sub = player.getSub();
	if (sub[0].flag == true) {
		MV1SetPosition(sub[0].MHandle, VGet(sub[0].x, sub[0].y, sub[0].z));
		MV1SetRotationXYZ(sub[0].MHandle, VGet(0.0f, sub[0].angy * DX_PI_F / 180.0f, 0.0f));
		MV1DrawModel(sub[0].MHandle);
	}
}

//敵の描画
void draw_Enemy() {
	substance *sub = enemy.getSub();
	for (int i = 0; i < enemy.getSize(); i++) {
		if (sub[i].flag == true) {
			MV1SetPosition(sub[i].MHandle, VGet(sub[i].x, sub[i].y, sub[i].z));
			MV1SetRotationXYZ(sub[i].MHandle,VGet(0.0f, sub[i].angy * DX_PI_F / 180.0f, 0.0f));
			MV1DrawModel(sub[i].MHandle);
		}
	}
}

//プレイヤー弾の描画
void draw_Player_shot() {
	substance *sub = player_shot.getSub();
	for (int i = 0; i < player_shot.getSize(); i++) {
		if (sub[i].flag == true) {
			DrawSphere3D(VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(0, 255, 255), GetColor(0, 0, 255), TRUE);
		}
	}
}

//敵の弾の描画
void draw_Enemy_shot() {
	substance *sub = enemy_shot.getSub();
	for (int i = 0; i < enemy_shot.getSize(); i++) {
		if (sub[i].flag == true) {
			DrawSphere3D(VGet(sub[i].x, sub[i].y, sub[i].z), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
		}
	}
}

//乱数の範囲を決める
int GetRandom(int min, int max) {
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

//aをbで割った余りを返す
float modulo(float a, float b) {
	return a - floorf(a / b) * b;
}

//塵の描画
void draw_Dust() {
	substance *sub = dust.getSub();
	substance *p = player.getSub();
	//乱数を時刻ごとに決める

	//塵の座標をランダムに決めるために、乱数を設定
	unsigned int seed = int(rand() % 1000 + 1);
	srand(0);

	//float range = 20.0f;		  
	float range = 500.0f;
	for (int i = 0; i < dust.getSize(); i++) {
		//遠くのものは点で描画
		sub[i].x = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		sub[i].y = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		sub[i].z = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		DrawPixel3D(VGet(sub[i].x, sub[i].y, sub[i].z), GetColor(255, 255, 255));

		//近くのものは線で描画 
		sub[i].x = (float)GetRandom(0, DUST_RANGE);
		sub[i].y = (float)GetRandom(0, DUST_RANGE);
		sub[i].z = (float)GetRandom(0, DUST_RANGE);
		sub[i].x = modulo(-p[0].x + sub[i].x, range) - range * 0.5f;
		sub[i].y = modulo(-p[0].y + sub[i].y, range) - range * 0.5f;
		sub[i].z = modulo(-p[0].z + sub[i].z, range) - range * 0.5f;
		DrawLine3D(VGet(sub[i].x, sub[i].y, sub[i].z), VGet(sub[i].x - p[0].x * (range * 0.001f) + 0.001f, sub[i].y - p[0].y * (range * 0.001f), sub[i].z - p[0].z * (range * 0.001f)), GetColor(255, 255, 255));
	}

	srand(seed);
}

//青い惑星の描画
void draw_Planet() {
	substance *sub = planet.getSub();
	DrawSphere3D(VGet(sub[0].x, sub[0].y, sub[0].z), PLANET_R, PLANET_DIVNUM, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
}

//エフェクトの描画
void draw_Effect() {
	effect* eff = player_shot.getEff();
	for (int i = 0; i < player_shot.getSize(); i++) {
		if (eff[i].flag == true) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, eff[i].br);
			DrawSphere3D(VGet(eff[i].x, eff[i].y, eff[i].z), eff[i].r, 8, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

//PlayerのHPの描画
void draw_Player_HP() {
	character *cha = player.getCha();
	int px = 480, py = 10;
	int addx = 100, addy = 15;
	unsigned int white = GetColor(255, 255, 255), ygreen = GetColor(0, 255, 0);//白、黄緑

	//HPの文字を表記
	DrawFormatString(px - 20, py, white, "HP");

	//四角の描画
	DrawBox(px, py, px + cha[0].hp - 1, py + addy - 1, ygreen, TRUE);

	//枠の描画
	DrawLine(px - 1                , py - 1        , px + cha[0].hp_max - 1 , py - 1       , white);//上横線
	DrawLine(px - 1                , py - 1        , px - 1                 , py + addy - 1, white);//左縦線
	DrawLine(px + cha[0].hp_max - 1, py - 1        , px + cha[0].hp_max - 1 , py + addy    , white);//右縦線
	DrawLine(px - 1                , py + addy - 1 , px + cha[0].hp_max - 1 , py + addy - 1, white);//下横線
}

//タイトルの描画
void draw_Title() {
	int FontHandle = CreateFontToHandle("HGS創英角ﾎﾟｯﾌﾟ体", 64, 8, DX_FONTTYPE_ANTIALIASING_EDGE);
	char *str = "Space Shooting";
	int Strlen = strlen(str);
	int Width = GetDrawStringWidthToHandle(str, Strlen, FontHandle);

	DrawStringToHandle(320 - Width / 2, 208, str, GetColor(255, 255, 255), FontHandle);


	/*フェードイン、フェードアウト*/

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, char_br);
	str = "スペースキーを押してください";
	Strlen = strlen(str);
	Width = GetDrawStringWidth(str, Strlen);
	DrawString(320 - Width / 2, 280, str, GetColor(255, 255, 255));

	//ブレンドを元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (char_br > 255 || char_br < 0) {
		i *= -1;
	}
	char_br += i;

	//フォントを削除
	DeleteFontToHandle(FontHandle);
}

//クリアの描画
void draw_GameClear() {
	int FontHandle = CreateFontToHandle("HGS創英角ﾎﾟｯﾌﾟ体", 64, 8, DX_FONTTYPE_ANTIALIASING_EDGE);
	char *str = "Game Clear!!";
	int Strlen = strlen(str);
	int Width = GetDrawStringWidthToHandle(str, Strlen, FontHandle);

	DrawStringToHandle(320 - Width / 2, 208, str, GetColor(255, 255, 255), FontHandle);


	/*フェードイン、フェードアウト*/

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, charClearOver);
	str = "スペースキーを押せば、もう一度プレイできます";
	Strlen = strlen(str);
	Width = GetDrawStringWidth(str, Strlen);
	DrawString(320 - Width / 2, 280, str, GetColor(255, 255, 255));

	//ブレンドを元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (charClearOver > 255 || charClearOver < 0) {
		i *= -1;
	}
	charClearOver += i;

	//フォントを削除
	DeleteFontToHandle(FontHandle);
}

//ゲームオーバーの描画
void draw_GameOver() {
	int FontHandle = CreateFontToHandle("HGS創英角ﾎﾟｯﾌﾟ体", 64, 8, DX_FONTTYPE_ANTIALIASING_EDGE);
	char *str = "Game Over....";
	int Strlen = strlen(str);
	int Width = GetDrawStringWidthToHandle(str, Strlen, FontHandle);

	DrawStringToHandle(320 - Width / 2, 208, str, GetColor(255, 255, 255), FontHandle);


	/*フェードイン、フェードアウト*/

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, charClearOver);
	str = "スペースキーを押せば、もう一度プレイできます";
	Strlen = strlen(str);
	Width = GetDrawStringWidth(str, Strlen);
	DrawString(320 - Width / 2, 280, str, GetColor(255, 255, 255));

	//ブレンドを元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (charClearOver > 255 || charClearOver < 0) {
		i *= -1;
	}
	charClearOver += i;

	//フォントを削除
	DeleteFontToHandle(FontHandle);
}

void draw() {
	if (play_mode == false) {
		draw_Title();
		if (keyboard.checkKey(KEY_INPUT_SPACE) == 1) {
			play_mode = true;
		}
	}
	else {
		if (over_flag == false) {
			SetUseZBuffer3D(TRUE);
			SetWriteZBuffer3D(TRUE);
			setCamera();
			draw_Planet();
			draw_Dust();
			draw_Player_shot();
			draw_Enemy_shot();
			draw_Player();
			draw_Enemy();
			draw_Effect();
			draw_Player_HP();
			if (clear_flag == true) {
				draw_GameClear();
				if (keyboard.checkKey(KEY_INPUT_SPACE) == 1) {
					play_mode = true;
					initialization();
				}
			}
			
		}
		else {
			draw_GameOver();
			if (keyboard.checkKey(KEY_INPUT_SPACE) == 1) {
				play_mode = true;
				initialization();
			}
		}
	}
}