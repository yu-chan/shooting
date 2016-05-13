#pragma once
class Music
{
public:
	music_ bgm, se[SE_NUM];
	//Music();
	//~Music();
	void se_initialization();
	void se_flag(int);
	void se_play(int);
	void load_bgm(int);
	void delete_bgm();
	void bgm_main();
};

