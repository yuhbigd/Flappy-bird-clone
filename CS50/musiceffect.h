#pragma once
#include<SDL_mixer.h>
#include<string>
#include<iostream>
using namespace std;
class musiceff
{
private:
	Mix_Music* music;
	int volume = 128;
public:
	musiceff()
	{
		music = NULL;
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