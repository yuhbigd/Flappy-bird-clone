#include "SplashScreen.h"
#include "Menustate.h"
void splashState::update()
{
	if (SDL_GetTicks() >= 2000)
	{
		gameinit::getG()->getGamestate()->changeState(new MenuState);
	}
}

void splashState::render()
{
	sPl.drawAll(gameinit::getG()->getRenderer());
}

bool splashState::onEnter()
{
	sPl.load(0, 0, 720, 480, "splash", 0);
	return true;
}

bool splashState::onExit()
{
	return true;
}
