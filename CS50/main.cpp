#include"CS50.h"
#include<ctime>
#include<cstdlib>;
#include<SDL_ttf.h>
int FPS = 50;
int DELAY_time = 1000.0 / FPS;//moi 20 milisec thi ve ra 1 hinh ->50 hinh/1s 
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
		frametime = SDL_GetTicks() - framestart;//so milisec de ve ra mot hinh
		if (frametime < DELAY_time)
		{
			SDL_Delay(DELAY_time - frametime);//neu nho hon 20 thi delay
		}
	}
	gameinit::getG()->quitSdl();
	return 0;

}

