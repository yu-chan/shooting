#include "./../../../h/global.h"


Shot::Shot()
{
}

/*
	自分が打った時、相手にあたってるかどうか判定する

	Sub : 相手(障害物、モデル)のアドレス
	cha : キャラクターのステータス
	v1 : ショットの座標
	ModelHandleFrameIndex : モデルのフレーム番号
	power : ショットのパワー
*/	 
bool Shot::collision_detection(Substance *Sub, character* cha, VECTOR v, int ModelHandleFrameIndex, int power) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int msize = mSub->getSize();

	for (int i = 0; i < msize; i++) {
		//コリジョン情報を構築する
		MV1SetupCollInfo(msub[i].MHandle, ModelHandleFrameIndex, 8, 8, 8);

		//相手のフラグがオンで、かつ当たってるならtrueを返す
		if (msub[i].flag == true) {
			HitPolyDim = MV1CollCheck_Sphere(msub[i].MHandle, ModelHandleFrameIndex, v, SHOT_CAPSULE_R);

			if (HitPolyDim.HitNum >= 1) {
				//コリジョン情報を更新する
				MV1RefreshCollInfo(msub[i].MHandle, ModelHandleFrameIndex);

				//HPを減らす
				cha[i].hp -= power;

				//HPが0になったら、モデルを消す
				if (cha[i].hp <= 0) {
					msub[i].flag = false;
					msub[i].fall_flag = true;
					
					if (cha[i].knd == 1) {//倒されたのが敵なら、増やす
						down_enemy_num++;
					} else if (cha[i].knd == 0) {//倒されたのがプレイヤーなら、over_flagをtrueにする
						over_flag = true;
					}
				}

				//コリジョン情報の後始末
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