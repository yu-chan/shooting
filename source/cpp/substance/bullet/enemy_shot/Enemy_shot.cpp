#include "./../../../../h/global.h"


Enemy_shot::Enemy_shot()
{
	mallocSub(1);
	mallocEff(getSize());
	memset(getSub(), 0, sizeof(substance) * getSize());
	memset(getEff(), 0, sizeof(effect) * getSize());
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
		if (sub[i].count != 0 && sub[i].count % 30 == 0 && sub[i].flag == true) {	
			for (int j = 0; j < getSize(); j++) {
				//�V���b�g�̃t���O���܂������ĂȂ��Ȃ�A�o�^����
				if (_sub[j].flag == false) {
					//���݂̓G�ƃv���C���[�̃x�N�g����ۑ�
					VECTOR cur_enemy = VGet(sub[i].x, sub[i].y, sub[i].z);
					VECTOR cur_player = VGet(player_sub.x, player_sub.y, player_sub.z);

					//�������߂�
					VECTOR p_e_sub = VSub(cur_player, cur_enemy);

					//���x�N�g������p�x�����߂�	   
					float p_e_angy = atan2(p_e_sub.z, p_e_sub.x) / DX_PI_F * 180.0f;

					_sub[j].x = sub[i].x;
					_sub[j].y = sub[i].y + SHOT_ENEMY_Y + 1;
					_sub[j].z = sub[i].z;

					_sub[j].vx = 2.0f * cos(p_e_angy * DX_PI_F / 180.0f);
					_sub[j].vz = 2.0f * sin(p_e_angy * DX_PI_F / 180.0f);

					_sub[j].count = 0;
					_sub[j].flag = true;

					//�V���b�g���̃t���O�𗧂Ă�
					music.se_flag(SHOT_NO);

					//�V���b�g���𗧂Ă�
					music.se_play(SHOT_NO);
					break;
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

			if (collision_detection(&player, player.getCha(), VGet(sub[i].x, sub[i].y, sub[i].z), -1, 1) == true) {
				sub[i].flag = false;
				effect_regist(VGet(sub[i].x, sub[i].y, sub[i].z));
				//OutputDebugStringW(L"Enemy_shot Hit!!\n");
				continue;
			}

			if (sub[i].count == 100) {
				sub[i].flag = false;
				//OutputDebugStringW(L"Enemy_shot Vanish!!\n");
			}
		}
	}
}