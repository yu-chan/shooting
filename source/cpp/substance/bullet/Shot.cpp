#include "./../../../h/global.h"


Shot::Shot()
{
}

/*
	�������ł������A����ɂ������Ă邩�ǂ������肷��

	Sub : ����(��Q���A���f��)�̃A�h���X
	cha : �L�����N�^�[�̃X�e�[�^�X
	v1 : �V���b�g�̍��W
	ModelHandleFrameIndex : ���f���̃t���[���ԍ�
	power : �V���b�g�̃p���[
*/	 
bool Shot::collision_detection(Substance *Sub, character* cha, VECTOR v, int ModelHandleFrameIndex, int power) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int msize = mSub->getSize();

	for (int i = 0; i < msize; i++) {
		//�R���W���������\�z����
		MV1SetupCollInfo(msub[i].MHandle, ModelHandleFrameIndex, 8, 8, 8);

		//����̃t���O���I���ŁA���������Ă�Ȃ�true��Ԃ�
		if (msub[i].flag == true) {
			HitPolyDim = MV1CollCheck_Sphere(msub[i].MHandle, ModelHandleFrameIndex, v, SHOT_CAPSULE_R);

			if (HitPolyDim.HitNum >= 1) {
				//�R���W���������X�V����
				MV1RefreshCollInfo(msub[i].MHandle, ModelHandleFrameIndex);

				//HP�����炷
				cha[i].hp -= power;

				//HP��0�ɂȂ�����A���f��������
				if (cha[i].hp <= 0) {
					msub[i].flag = false;
					msub[i].fall_flag = true;
					
					if (cha[i].knd == 1) {//�|���ꂽ�̂��G�Ȃ�A���₷
						down_enemy_num++;
					} else if (cha[i].knd == 0) {//�|���ꂽ�̂��v���C���[�Ȃ�Aover_flag��true�ɂ���
						over_flag = true;
					}
				}

				//�R���W�������̌�n��
				MV1CollResultPolyDimTerminate(HitPolyDim);

				return true;
			}
		}
	}

	return false;
}

void Shot::effect_regist(VECTOR v) { 
	for (int i = 0; i < getSize(); i++) {
		if (eff[i].flag == false) {
			eff[i].flag = true;
			eff[i].x = v.x;
			eff[i].y = v.y;
			eff[i].z = v.z;
			eff[i].r = 0;
			eff[i].br = 255;
		}
	}
}

void Shot::calc_effect() { 
	for (int i = 0; i < getSize(); i++) {
		if (eff[i].flag == true) {
			eff[i].r +=0.5f;
			eff[i].br -= 5;

			if (eff[i].br <= 0) {
				eff[i].flag = false;
			}
		}
	}
}

effect* Shot::getEff() {
	return eff;
}

void Shot::mallocEff(int n) {
	eff = (effect*)malloc(sizeof(effect) * getSize());
}