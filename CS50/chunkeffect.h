#pragma once
#include<SDL_mixer.h>
#include<string>
#include <fstream>
#include<iostream>
using namespace std;
class chunkeff
{
private:
	Mix_Chunk* chunk;
	int volume;
	string filename;
public:
	chunkeff()
	{
		volume = 0;
		chunk = NULL;
	}
	void init(string filename);
	int getvolume()
	{
		return volume;
	}
	void setvolume(int n)
	{
		ofstream file;
		file.open("chunkvolume.txt");
		file << n;
		volume = n;
		pausechunk();
		playmusic();
	}
	string getfilename()
	{
		return filename;
	}
	void playmusic();
	void pausechunk();
	void resumechunk();
};
