#include "./../../../../h/global.h"


//float x = 0, y = 0;
static const float ROTATE_SPEED = 1.0f * DX_PI_F / 180.0f; //回転スピード

void ini(substance* s, character* c) {
	substance *sub = s;
	s[0].x = 0;
	s[0].y = 0;
	s[0].z = 0;
	s[0].flag = true;
	s[0].vx = 0;
	s[0].vy = 0;
	s[0].vz = 0;
	c[0].hp_max = 10;
	c[0].hp = c[0].hp_max;
}

Player::Player()
{
	mallocSub(1);
	mallocCha(1);
	ini(getSub(), getCha());
}


Player::~Player()
{
	free(getSub());
}

void Player::move() {
	substance *sub;
	character* cha = getCha();
	sub = getSub();
	if (sub == NULL)OutputDebugStringW(L"ポインタ違う\n");
	if (getSub() == NULL)OutputDebugStringW(L"とりあえず\n");

	//動く前のプレイヤーとカメラの座標を保存
	VECTOR pre_player = VGet(sub[0].x, sub[0].y, sub[0].z);
	VECTOR pre_camera_pos = camera_pos, pre_camera_look = camera_look;


	//右が押されてたら、右に移動
	if (keyboard.checkKey(KEY_INPUT_RIGHT)) {
		sub[0].vx = 1.0f * cos(-(sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		sub[0].vz = 1.0f * sin(-(sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		sub[0].x += sub[0].vx;
		sub[0].z += sub[0].vz;
	}

	//左が推されてたら、左に移動
	if (keyboard.checkKey(KEY_INPUT_LEFT)) {
		sub[0].vx = -1.0f * cos(-(sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		sub[0].vz = -1.0f * sin(-(sub[0].angy - 180.0f) * DX_PI_F / 180.0f);	
		sub[0].x += sub[0].vx;
		sub[0].z += sub[0].vz;
	}

	//上が押されてたら、前に移動
	if (keyboard.checkKey(KEY_INPUT_UP)) {
		sub[0].vx = 1.0f * cos((90 - (sub[0].angy - 180.0f)) * DX_PI_F / 180.0f);
		sub[0].vz = 1.0f * sin((90 - (sub[0].angy - 180.0f)) * DX_PI_F / 180.0f);
		sub[0].x += sub[0].vx;
		sub[0].z += sub[0].vz;
	}

	//モデルが動いたら、カメラも動けるようにする
	VECTOR player_sub = VSub(VGet(sub[0].x, sub[0].y, sub[0].z), pre_player);
	camera_pos = VAdd(camera_pos, player_sub);
	camera_look = VAdd(camera_look, player_sub);

	//モデルが回転する
	if (keyboard.checkKey(KEY_INPUT_Z)) {
		float rot = ROTATE_SPEED / DX_PI_F * 180.0f;
		//float angy = sub[0].angy + rot;
		float angy = sub[0].angy + ROTATE_SPEED / DX_PI_F * 180.0f;
		MATRIX matrix = MGetRotY(ROTATE_SPEED);

		//sub[0].angy += ROTATE_SPEED / DX_PI_F * 180.0f;

		//Zキーを押してるなら、逆回転
		if (keyboard.checkKey(KEY_INPUT_LSHIFT)) { 
			angy = sub[0].angy - ROTATE_SPEED / DX_PI_F * 180.0f;
			matrix = MGetRotY(-ROTATE_SPEED);
		}

		sub[0].angy = angy;

		/*動く前後の座標の差を求める*/
		VECTOR player_sub = VSub(VGet(sub[0].x, sub[0].y, sub[0].z), pre_player);//プレイヤーの前後のベクトルの差
		VECTOR p_cp_sub = VSub(pre_camera_pos, pre_player);//動く前のカメラの座標とプレイヤーの差
		VECTOR p_cl_sub = VSub(pre_camera_look, pre_player);//動く前のカメラの注視点とプレイヤーの差

		//プレイヤーが回転していれば、それに応じてカメラの座標と注視点を変える
		camera_pos = VTransform(p_cp_sub, matrix);
		camera_pos = VAdd(camera_pos, VGet(sub[0].x, sub[0].y, sub[0].z));
		camera_look = VTransform(p_cl_sub, matrix);
		camera_look = VAdd(camera_look, VGet(sub[0].x, sub[0].y, sub[0].z));
	}
}