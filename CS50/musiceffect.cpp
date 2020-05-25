#include "musiceffect.h"

void musiceff::playafterSetting()
{
	init(filename);
	Mix_VolumeMusic(volume);
	Mix_PlayMusic(music, -1);
}

void musiceff::init(string filename)
{
	ifstream file;
	file.open("musicvolume.txt");
	file >> volume;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	music = Mix_LoadMUS(filename.c_str());
	if (music == NULL)
	{
		cout << Mix_GetError() << endl;
	}
	this->filename = filename;
}

void musiceff::playmusic()
{
	Mix_VolumeMusic(volume);
	Mix_PlayMusic(music, -1);
}

void musiceff::pausechunk()
{
	Mix_PauseMusic();
}

void musiceff::resumechunk()
{
	Mix_ResumeMusic();
}
