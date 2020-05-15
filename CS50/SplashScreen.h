#pragma once
#include"CS50.h"
#include"BackGround.h"
#include"Gamestate.h"


class splashState :public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();
private:
	Background sPl;
};