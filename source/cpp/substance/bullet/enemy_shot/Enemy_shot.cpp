#include "./../../../../h/global.h"


Enemy_shot::Enemy_shot()
{
	mallocSub(1);
}


Enemy_shot::~Enemy_shot()
{
	free(getSub());
}

void Enemy_shot::shot_regist() {
	substance *sub = enemy.getSub();
	substance *_sub = getSub();
	for (int i = 0; i < getSize(); i++) {
		//�G���o�����Ă��瑝�������Ԃ��V���b�g��ł��ԂƓ����ɂȂ�����A�e��ł�
		if (sub[i].count == 30) {
			//DrawFormatString(0, 0, GetColor(255, 255, 255), "count:%d", _sub[i].count);
			_sub[i].x = sub[i].x;
			_sub[i].y = sub[i].y;
			_sub[i].z = sub[i].z;
			_sub[i].vz = -0.1f;
			_sub[i].count = 0;
			_sub[i].flag = true;
			//�V���b�g���̃t���O�𗧂Ă�
			music.se_flag(SHOT_NO);
		}
		music.se_play(SHOT_NO);
	}
}

//bool Enemy_shot::collision_detection() {
//	return false;
//}

void Enemy_shot::move() {
	substance *sub = getSub();
	for (int i = 0; i < getSize(); i++) {
		if (sub[i].flag == true) {
			sub[i].z += sub[i].vz;
			sub[i].count++;
			//DrawFormatString(0, 0, GetColor(255, 255, 255), "count:%d", sub[i].count);

			//����ɓ������Ă�Ȃ�A�t���O������
			/*if (collision_detection(&player, VGet(sub[i].x, sub[i].y + 10, sub[i].z), VGet(sub[i].x, sub[i].y + 10, sub[i].z + 5), ModelAirCraft, PLAYER_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
			}*/
			if (collision_detection(&player, VGet(sub[i].x, sub[i].y + 10, sub[i].z), ModelAirCraft, PLAYER_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
			}

			//�͈͊O�ɏo����t���O������
			/*
			�e���o�Ă��邩�m�F���Ă��邽�߁A�͈͂��������Ă���
			���Ƃɔ͈͂�ς���K�v������
			*/
			/*if (sub[i].x < SHOT_RANGE_X_MIN || sub[i].x > SHOT_RANGE_X_MAX ||
				sub[i].y < SHOT_RANGE_Y_MIN || sub[i].y > SHOT_RANGE_Y_MAX ||
				sub[i].z < SHOT_RANGE_Z_MIN || sub[i].z > SHOT_RANGE_Z_MAX) {
				sub[i].flag = false;
			}*/	 
			if (sub[i].x < SHOT_RANGE_X_MIN || sub[i].x > SHOT_RANGE_X_MAX ||
				sub[i].y < SHOT_RANGE_Y_MIN || sub[i].y > SHOT_RANGE_Y_MAX ||
				sub[i].z < SHOT_RANGE_Z_MIN) {
				sub[i].flag = false;
			}
		}
	}
}