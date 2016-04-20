#include "./../../../h/global.h"


Item::Item()
{
	mallocSub(ITEM_KIND_NUM);
	ite = (item *)malloc(sizeof(item) * ITEM_KIND_NUM);
	memset(getSub(), 0, sizeof(substance) * getSize());
}


Item::~Item()
{
	free(getSub());
	free(ite);
}

item* Item::getIte() {
	return ite;
}

void Item::item_regist(int kind, substance s) {
	substance *sub = getSub();
	if (sub[kind].flag == false) {
		sub[kind].flag = true;
		sub[kind].x = s.x;
		sub[kind].y = s.y;
		sub[kind].z = s.z;
		sub[kind].vz = -0.1f;
		sub[kind].count = 0;
	}
}

void Item::move() {
	substance *sub = getSub();
	for (int i = 0; i < getSize(); i++){
		if (sub[i].flag == true) {
			sub[i].z += sub[i].vz;
			sub[i].count++;

			//範囲外に出たらフラグを消す
			if (sub[i].x < SHOT_RANGE_X_MIN || sub[i].x > SHOT_RANGE_X_MAX ||
				sub[i].y < SHOT_RANGE_Y_MIN || sub[i].y > SHOT_RANGE_Y_MAX ||
				sub[i].z < SHOT_RANGE_Z_MIN || sub[i].z > SHOT_RANGE_Z_MAX) {
				sub[i].flag = false;
			}
		}
	}
}