#include "./../../../../h/global.h"


Enemy::Enemy()
{
	mallocSub(1);
	substance *sub = getSub();
}


Enemy::~Enemy()
{
	free(getSub());
}

void Enemy::move() {
	substance *sub = getSub();
	substance *sub_ = player.getSub();
	////character &cha = *getCha();
	for (int i = 0; i < getSize(); i++) {
		if (sub[i].flag == true) {

			/*���W*/
			//�����O�̓G�A�v���C���[�̍��W��ۑ�
			VECTOR pre_enemy = VGet(sub[i].x, sub[i].y, sub[i].z);
			VECTOR pre_player = VGet(sub_[0].x, sub_[0].y, sub_[0].z);

			//�v���C���[�ƓG�̃x�N�g���̍�
			VECTOR p_e_sub = VSub(pre_player, pre_enemy);

			//�x�N�g���̃T�C�Y�����߂�
			float vsize = VSize(p_e_sub);

			//�G���v���C���[�̕��ւ̈ړ��ʂ�0.1�ɂ���
			p_e_sub = VScale(p_e_sub, 1 / (10 * vsize));

			sub[i].x += p_e_sub.x;
			sub[i].y += p_e_sub.y;
			sub[i].z += p_e_sub.z;
			DrawFormatStringF(0.0f, 60.0f, GetColor(255, 255, 255), "Enemy �ʒuX : %f �ʒuZ : %f", sub[i].x, sub[i].z);


			/*�p�x*/
			//�����O�̊p�xy��ۑ�
			float pre_angy = sub[i].angy;

			//���x�N�g������p�xy�����߂�
			float p_e_angy = atan2(p_e_sub.z, p_e_sub.x) / DX_PI_F * 180.0f;
			DrawFormatStringF(0.0f, 0.0f, GetColor(255, 255, 255), "�x�N�g���p�xY : %f", p_e_angy);

			//�p�xy�̍��������߂�
			float angy_sub = p_e_angy - pre_angy;
			DrawFormatStringF(0.0f, 20.0f, GetColor(255, 255, 255), "���p�xY : %f", angy_sub);

			//�p�x�����߂�
			//sub[i].angx = acos(p_e_sub.z / vsize);
			//sub[i].angy += angy_sub;
			//sub[i].angy += angy_sub;
			sub[i].angy = p_e_angy - 90.0f;
			//sub[i].angz = acos(p_e_sub.y / vsize);
			DrawFormatStringF(0.0f, 80.0f, GetColor(255, 255, 255), "Enemy�p�xY : %f", sub[i].angy);

			sub[i].count++;
		}
	}
}

void Enemy::enemy_regist() {   
	substance *sub = getSub();

	for (int i = 0; i < getSize(); i++) {
		//�G�̏o�����ԂƃX�e�[�W�̃J�E���g�������Ȃ�A�G���o��������
		if (sub[i].aptime == stage_count) {
			sub[i].flag = true;
			sub[i].count = 0;
		}
	}
}