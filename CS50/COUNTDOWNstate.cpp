#include "COUNTDOWNstate.h"
void countdownState::update()
{
	a++;
	back[1].setpos(back[0].getposx() + 1156);
	back[3].setpos(back[2].getposx() + 1100);
	for (int i = 0; i < 4; i++)
	{
		back[i].updateimage();
	}
	if (a > 150&&ispause==false)
	{
		gameinit::getG()->getGamestate()->changeState(new playState());
	}
	if (a > 150&&ispause==true)
	{
		gameinit::getG()->getGamestate()->popState();
	}
}

void countdownState::render()
{
	for (int i = 0; i <4; i++)
	{
		back[i].draw(gameinit::getG()->getRenderer());
	}
	if (a < 50)
	{
		count2->draw(400, 250);
	}
	if (a > 50&& a<100)
	{
		count1->draw(400, 250);
	}
	if (a > 100)
	{
		count0->draw(400, 250);
	}
}
bool countdownState::onEnter()
{
	a = 0;
	back[0].load(0, 0, 1157, 600, 0, 0, 1157, 600, "background", 1);
	back[0].setv(1);
	back[1].load(0, 0, 1157, 600, 0, 0, 1157, 600, "background", 1);
	back[1].setv(1);
	//back[2].loadimage("asset/ground.png", "ground1", gameinit::getG()->getRenderer());
	back[2].load(0, 0, 1100, 16, 0, 600 - 16, 1100, 16, "ground", 1);
	back[3].load(0, 0, 1100, 16, 0, 600 - 16, 1100, 16, "ground", 1);
	back[3].setv(2);
	back[2].setv(2);
	return true;
}

bool countdownState::onExit()
{
	
		count0->clean();
		count1->clean();
		count2->clean();
		delete count0;
		delete count1;
		delete count2;
	return true;
}
