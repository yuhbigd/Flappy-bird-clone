#include"CS50.h"
#include"MENUSTATE.h"
#include"playstate.h"
#include"inputHandle.h"
gameinit* gameinit::ginstance = 0;

bool gameinit::init(string title, int xpos, int ypos, int width, int height)
{

	if (SDL_INIT_EVERYTHING < 0)
	{
		cout << "error" << SDL_GetError << endl;
		return false;
	}
	window = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(render, 0, 0, 255, 0);
	imageManage::getImage()->load("asset/button.png", "play", render);
	imageManage::getImage()->load("asset/background.png", "background", render);
	imageManage::getImage()->load("asset/ground.png", "ground", render);
	imageManage::getImage()->load("asset/arrow.png", "arrow", render);
	imageManage::getImage()->load("asset/bird.png", "bird", render);
	imageManage::getImage()->load("asset/birddown.png", "birddown", render);
	imageManage::getImage()->load("asset/pipe.png", "pipe", render);
	imageManage::getImage()->load("asset/exit.png", "exit", render);
	imageManage::getImage()->load("asset/board.png", "board", render);
	imageManage::getImage()->load("asset/menu.png", "menu", render);
	imageManage::getImage()->load("asset/restart.png", "restart", render);
	gamestate = new GameStateMachine();	
	gamestate->pushState(new MenuState());

	running = true;
	return true;
}

void gameinit::handle()
{
	input::getInput()->update();
}

void gameinit::renderer()
{

	SDL_RenderClear(render);
	gamestate->render();
	SDL_RenderPresent(render);
}

void gameinit::update()
{
	gamestate->update();
	
}

void gameinit::quitSdl()
{
	running = false;
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
}
