// shooting/source/cpp/initialization

#include "./../../h/global.h"

//���낢��Ȃ��̂�������
void initialization() {
	//�v���C���[�̃��f����Y����180�x��]�����邽�߂�angy��������
	substance *sub = player.getSub();
	character *cha = player.getCha();
	sub[0].x = 0;
	sub[0].y = 0;
	sub[0].z = 0;
	sub[0].flag = true;
	sub[0].fall_flag = false;
	sub[0].angy = 180.0f;
	cha[0].hp = cha[0].hp_max;

	//�J�����̍��W�A�����_������������
	camera_pos = VGet(sub[0].x, sub[0].y + 10.0f, sub[0].z - 30); //�J�����̈ʒu
	camera_look = VGet(0.0f, 0.0f, 30.0f); //�J�����̒����_(�J�����̍��W���瑫��������)
	camera_look = VAdd(camera_pos, camera_look);

	//�X�e�[�W�̃J�E���g��0�ɂ���
	stage_count = 0;

	//�v���C���[�h��false�ɂ���
	play_mode = false;

	//�N���A�A�I�[�o�[�t���O��false�ɂ���
	clear_flag = false;
	over_flag = false;

	//�|�����G�̐���0�ɂ���
	down_enemy_num = 0;


	//�G�̃��f����Y����180�x��]�����邽�߂�angy��������
	sub = enemy.getSub();
	cha = enemy.getCha();
	int size = enemy.getSize();
	for (int i = 0; i < size; i++) {
		//sub[i].angy = -90.0f;			 
		sub[i].angy = 0.0f;
		sub[i].flag = false;
		sub[i].fall_flag = false;
		cha[i].hp = 10;
		cha[i].knd = 1;
	}

	//�o�̏�����
	dust.mallocSub(DUST_NUM);
}