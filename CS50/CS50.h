#ifndef _GAME_
#define _GAME_
#include<SDL.h>
#include<iostream>
#include"texturemanage.h"
#include"gameobj.h"
#include"FLAPPY.h"
#include"gamestatemachine.h"
#include"PIPE.h"
#include"BackGround.h"
#include<vector>
using namespace std;
class gameinit
{
private:
	static gameinit* ginstance;
	bool running;
	SDL_Window* window;
	SDL_Renderer* render;
	GameStateMachine* gamestate;
	gameinit()
	{
		gamestate = NULL;
		running = true;
		window = nullptr;
		render = nullptr;
	}
	~gameinit()
	{
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		delete[]render;
		delete window;
		delete[]gamestate;
		delete[]ginstance;
	}
public:
	GameStateMachine* getGamestate()
	{
		return this->gamestate;
	}
	bool isrun()
	{
		return running;
	}
	SDL_Renderer* getRenderer() const { return render; }
	static gameinit* getG()
	{
		if (ginstance == 0)
		{
			ginstance = new gameinit();
		}
		return ginstance;
	}
	bool init(string title, int xpos, int ypos, int width, int height);
	void handle();
	void renderer();
	void update();
	void quitSdl();
	void setrun(bool ab)
	{
		running = ab;
	}
};
#endif // !_GAME_


