#include "MENUSTATE.h"
#include "CS50.h"
#include"inputHandle.h"
#include"COUNTDOWNstate.h"
#include"playstate.h"
#include"settingState.h"
void MenuState::update()
{
	back[1].setpos(back[0].getposx() + 1156);//background phia dang sau dung 2 anh voi vi tri anh 2 =vitri anh 1+1156(do rong cua anh 1)
	back[3].setpos(back[2].getposx() + 1100);//ground
	for (int i = 0; i < 7; i++)
	{
		back[i].updateimage();
	}
	if (input::getInput()->getmousebutt(LEFT) == true)
	{
		if (input::getInput()->getmouposX() >= 356 && input::getInput()->getmouposX() <= 444
			&& input::getInput()->getmouposY() >= 264 && input::getInput()->getmouposY() <= 338)
		{
			mBack.pausechunk();
			gameinit::getG()->getGamestate()->changeState(new countdownState());
		}
		if (input::getInput()->getmouposX() >= 700 &&input::getInput()->getmouposX() <= 800
			&& input::getInput()->getmouposY() >= 0 && input::getInput()->getmouposY() <= 100)
		{
			gameinit::getG()->quitSdl();
		}
		if (input::getInput()->getmouposX() >= 750 && input::getInput()->getmouposX() <= 800
			&& input::getInput()->getmouposY() >= 550 && input::getInput()->getmouposY() <= 600)
		{
			gameinit::getG()->getGamestate()->pushState(new settingState());
			afterSetting = true;
		}
	}
	if (input::getInput()->getkeybutt(_SPACE_) == true)
	{
		mBack.pausechunk();
		gameinit::getG()->getGamestate()->changeState(new countdownState());
	}
}
void MenuState::render()
{
	for (int i = 0; i < 5; i++)
	{
		back[i].draw(gameinit::getG()->getRenderer());
	}
	if (int(SDL_GetTicks() / 1000 % 2) == 1)
	{
		back[5].draw(gameinit::getG()->getRenderer());//mui ten nhap nhay
	}
	c->draw(100, 50);
	back[6].draw(gameinit::getG()->getRenderer());
	setting.draw(gameinit::getG()->getRenderer());
	if (afterSetting == true)
	{
		//vi da pausechunk o settingstate truoc len can phai play lai init lai nhac vi am luong da thay doi
		mBack.init(mBack.getfilename());
		mBack.playmusic();
		afterSetting = false;
	}
}
bool MenuState::onEnter()
{
	back[0].load(0,0,1157,600,0,0,1157,600, "background",1);
	back[0].setv(1);
	back[1].load(0, 0, 1157, 600, 0, 0, 1157, 600, "background", 1);
	back[1].setv(1);
	back[2].load(0, 0, 1100, 16, 0, 600 - 16, 1100, 16, "ground", 1);
	back[3].load(0, 0, 1100, 16, 0, 600 - 16, 1100, 16, "ground", 1);
	back[3].setv(2);
	back[2].setv(2);
	back[4].load(0,0,100,100,350, 250, 100,100, "play", 1);
	back[5].load(0,0,48,48,375, 200, 48, 48, "arrow", 1);
	back[6].load(0,0,100,100,700, 0, 100, 100, "exit", 1);
	setting.load(0, 0, 128, 128, 750, 550, 50, 50, "setting", 1);
	mBack.init("flappy.mp3");
	mBack.playmusic();
	afterSetting = false;
	return true;
}

bool MenuState::onExit()
{
	return true;
}
