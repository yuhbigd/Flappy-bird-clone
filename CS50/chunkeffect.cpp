#include"chunkeffect.h"
void chunkeff::init(string filename)
{
	ifstream file;
	file.open("chunkvolume.txt");
	file >> volume;
  	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	chunk = Mix_LoadWAV(filename.c_str());
	this->filename = filename;
	if (chunk == NULL)
	{
		cout << Mix_GetError() << endl;
	}
}

void chunkeff::playmusic()
{
	Mix_VolumeChunk(chunk, volume);
	Mix_PlayChannel(-1, chunk, 0);
}

void chunkeff::pausechunk()
{
	Mix_Pause(-1);//tu do chon
}

void chunkeff::resumechunk()
{
	Mix_Resume(-1);
}
