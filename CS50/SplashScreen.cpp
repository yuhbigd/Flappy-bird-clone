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
	sPl.draw(gameinit::getG()->getRenderer());
}

bool splashState::onEnter()
{
	sPl.load(0,0,868,355,0, 0,800,600, "splash", 1);
	return true;
}

bool splashState::onExit()
{
	return true;
}
