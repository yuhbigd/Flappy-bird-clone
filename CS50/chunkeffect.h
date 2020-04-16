#pragma once
#include<SDL_mixer.h>
#include<string>
#include<iostream>
using namespace std;
class chunkeff
{
private:
	Mix_Chunk* chunk=NULL;
	int volume = 128;
public:
	chunkeff()
	{
		chunk = NULL;
	}
	void init(string filename);
	void setvolume(int n)
	{
		volume = n;
	}
	void playmusic();
	void pausechunk();
	void resumechunk();
};
