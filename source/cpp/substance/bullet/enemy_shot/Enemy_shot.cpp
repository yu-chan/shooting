#include "./../../../../h/global.h"


Enemy_shot::Enemy_shot()
{
	mallocSub(1);
	memset(getSub(), 0, sizeof(substance) * getSize());
}


Enemy_shot::~Enemy_shot()
{
	free(getSub());
}

void Enemy_shot::shot_regist() {
	substance *sub = enemy.getSub();
	substance player_sub = player.getSub()[0];
	substance *_sub = getSub();

	for (int i = 0; i < enemy.getSize(); i++) {
		//�G���o�����Ă��瑝�������Ԃ��V���b�g��ł��ԂƓ����ɂȂ�����A�e��ł�
		if (sub[i].count % 30 == 0 && sub[i].flag == true) {	
			for (int j = 0; j < getSize(); j++) {
				//�V���b�g�̃t���O���܂������ĂȂ��Ȃ�A�o�^����
				if (_sub[j].flag == false) {
					//���݂̓G�ƃv���C���[�̃x�N�g����ۑ�
					VECTOR cur_enemy = VGet(sub[i].x, sub[i].y, sub[i].z);
					VECTOR cur_player = VGet(player_sub.x, player_sub.y, player_sub.z);

					//�������߂�
					VECTOR p_e_sub = VSub(cur_player, cur_enemy);

					//�T�C�Y�����߂�
					//float vsize = VSize(p_e_sub);

					//�ړ��ʂ�0.2�ɂ���
					//p_e_sub = VScale(p_e_sub, 0.2f * 1 / vsize);

					//���x�N�g������p�x�����߂�	   
					float p_e_angy = atan2(p_e_sub.z, p_e_sub.x) / DX_PI_F * 180.0f;
					//float p_e_angy = atan2(p_e_sub.z, p_e_sub.x);

					_sub[j].x = sub[i].x;
					_sub[j].y = sub[i].y + SHOT_ENEMY_Y + 1;
					_sub[j].z = sub[i].z;

					_sub[j].vx = 2.0f * cos(p_e_angy * DX_PI_F / 180.0f);
					_sub[j].vz = 2.0f * sin(p_e_angy * DX_PI_F / 180.0f);
					//_sub[i].vz = -0.1f;

					_sub[j].count = 0;
					_sub[j].flag = true;

					//�V���b�g���̃t���O�𗧂Ă�
					music.se_flag(SHOT_NO);

					//�V���b�g���𗧂Ă�
					music.se_play(SHOT_NO);
					break;
				}
				else {
					OutputDebugStringW(L"Enemy_shot true\n");
				}
			}
		}
	}
}

void Enemy_shot::move() {
	substance *sub = getSub();
	for (int i = 0; i < getSize(); i++) {
		if (sub[i].flag == true) {
			sub[i].x += sub[i].vx;
			sub[i].z += sub[i].vz;
			sub[i].count++;
			//DrawFormatString(0, 0, GetColor(255, 255, 255), "count:%d", sub[i].count);

			//����ɓ������Ă�Ȃ�A�t���O������
			/*if (collision_detection(&player, VGet(sub[i].x, sub[i].y + 10, sub[i].z), VGet(sub[i].x, sub[i].y + 10, sub[i].z + 5), ModelAirCraft, PLAYER_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
			}*/
			/*if (collision_detection(&player, VGet(sub[i].x, sub[i].y + SHOT_ENEMY_Y, sub[i].z + SHOT_ENEMY_Z), ModelAirCraft, PLAYER_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
			}*/	   
			/*if (collision_detection(&player, VGet(sub[i].x, sub[i].y, sub[i].z), -1) == true) {
				sub[i].flag = false;
				OutputDebugStringW(L"Enemy_shot Hit!!\n");
				continue;
			}*/	     
			if (collision_detection(&player, player.getCha(), VGet(sub[i].x, sub[i].y, sub[i].z), -1, 1) == true) {
				sub[i].flag = false;
				OutputDebugStringW(L"Enemy_shot Hit!!\n");
				continue;
			}

			//�͈͊O�ɏo����t���O������
			/*if (sub[i].x < SHOT_RANGE_X_MIN || sub[i].x > SHOT_RANGE_X_MAX ||
				sub[i].y < SHOT_RANGE_Y_MIN || sub[i].y > SHOT_RANGE_Y_MAX ||
				sub[i].z < SHOT_RANGE_Z_MIN) {
				sub[i].flag = false;
			}*/

			if (sub[i].count == 100) {
				sub[i].flag = false;
				OutputDebugStringW(L"Enemy_shot Vanish!!\n");
			}
		}
	}
}