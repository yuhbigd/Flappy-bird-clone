#pragma once
#include"Gamestate.h"
#include"FILETEXT.h"
#include "musiceffect.h"
#include"BackGround.h"
#include"chunkeffect.h"
#include<fstream>
class settingState : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	settingState() :GameState()
	{
		ifstream file;
		file.open("chunkvolume.txt");
		ifstream file1;
		file1.open("musicvolume.txt");
		file >> volumeChunk;
		file1 >> volumeMusic;   
		isrun = false;
		isrunchunk = false;
		largechunk = false;
		largemusic = false;
		sC= new textt(30, "SOUND");
		cC = new textt(30, "CHUNK");
		soundValue = new textt(20,"0");
		chunkValue = new textt(20,"0");
	}
	void changemusic();
	void changechunk();
	void changeMuteicon();
	void tValue();
private:
	chunkeff test;
	musiceff test2;
	double volumeMusic;
	double volumeChunk;
	bool isrun;
	bool isrunchunk;
	bool largechunk;
	bool largemusic;
	Background back;
	Background back1;
	Background sound[2];
	Background bar[2];
	Background circle[2];
	textt* sC;
	textt* cC;
	textt* soundValue;
	textt* chunkValue;
};


