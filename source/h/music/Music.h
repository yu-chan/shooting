#pragma once
class Music
{
public:
	music_ bgm[BGM_NUM], se[SE_NUM];
	//Music();
	//~Music();
	void se_initialization();
	void se_flag(int);
	void se_play(int);
	void load_bgm(int , int);
	void delete_bgm(int);
	void bgm_main();
};

