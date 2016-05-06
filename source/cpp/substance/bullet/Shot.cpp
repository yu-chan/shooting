#include "./../../../h/global.h"


Shot::Shot()
{
}

/*
	自分が打った時、相手にあたってるかどうか判定する

	Sub:相手(障害物、モデル)のアドレス
	v1, v2:自分のベクトル
*/
bool Shot::collision_detection(Substance *Sub, VECTOR v1, VECTOR v2) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	int msize = mSub->getSize();
	for (int i = 0; i < msize; i++) {
		//相手のフラグがオンで、かつ当たってるならtrueを返す
		if (msub[i].flag == true) {
			MV1_COLL_RESULT_POLY_DIM HitPolyDim = MV1CollCheck_Capsule(ModelEnemy, ENEMY_MODEL_FRAMEINDEX, v1, v2, SHOT_CAPSULE_DIVNUM);
			if (HitPolyDim.HitNum >= 1) {
				return true;
			}
		}
	}
	return false;
}

bullet* Shot::getBul() {
	return &bul;
}