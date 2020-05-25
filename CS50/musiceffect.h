#pragma once
#include<SDL_mixer.h>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class musiceff
{
private:
	Mix_Music* music;
	int volume;
	string filename;
public:
	musiceff()
	{	
		music = NULL;
		filename = "";
	}
	int vol()
	{
		return volume;
	}
	void playafterSetting();
	void init(string filename);
	void setvolume(int n)
	{
		ofstream file;
		file.open("musicvolume.txt");
		file << n;
		volume = n;
		pausechunk();
		playmusic();
	}
	void playmusic();
	void pausechunk();
	void resumechunk();
};