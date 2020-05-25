#pragma once
#include"Gamestate.h"
#include"BackGround.h"
#include"playstate.h"
#include"COUNTDOWNstate.h"
#include"MENUSTATE.h"
#include"inputHandle.h"
#include"settingState.h"
class pauseState : public GameState
{
public:
	void update();
	void render();

	bool onEnter();
	bool onExit();
	pauseState()
	{
		detail = new textt(60,"Return");
		onButt = false;
	}
private:
	bool onButt;
	Background back[8];
	textt* detail;
};

