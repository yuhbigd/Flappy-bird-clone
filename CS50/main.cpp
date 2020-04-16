#include"CS50.h"
#include<ctime>
#include<cstdlib>;
#include<SDL_ttf.h>
int FPS = 50;
int DELAY_time = 1000.0 / FPS;
int main(int agrc, char** args)
{
	srand(time(NULL));
	int framestart, frametime;
	string a = "12345";
	gameinit::getG()->init(a, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);
	
	while (gameinit::getG()->isrun())
	{
		framestart = SDL_GetTicks();
		gameinit::getG()->handle();
		gameinit::getG()->update();
		gameinit::getG()->renderer();
		frametime = SDL_GetTicks() - framestart;
		if (frametime < DELAY_time)
		{
			SDL_Delay(DELAY_time - frametime);
		}
	}
	gameinit::getG()->quitSdl();
	return 0;

}

