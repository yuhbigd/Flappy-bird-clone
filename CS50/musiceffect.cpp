#include "musiceffect.h"

void musiceff::init(string filename)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	music = Mix_LoadMUS(filename.c_str());
	if (music == NULL)
	{
		cout << Mix_GetError() << endl;
	}
}

void musiceff::playmusic()
{
	Mix_Volume(-1, volume);
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
