#include "PauseState.h"

void pauseState::update()
{
	back[1].setpos(back[0].getposx() + 1156);//ve background
	back[3].setpos(back[2].getposx() + 1100);
	for (int i = 0; i < 4; i++)
	{
		back[i].updateimage();
	}
	if (input::getInput()->getmouposX() >= 200 && input::getInput()->getmouposX() <= 300 && input::getInput()->getmouposY() >= 350 && input::getInput()->getmouposY() <= 450)
	{
		detail->setText("RETURN");
		detail->setSize(6);
		onButt = true;
		if (input::getInput()->getmousebutt(LEFT) == true)
		{
			gameinit::getG()->getGamestate()->changeState(new countdownState(true));
		}
		return;
	}
	else {
		onButt = false;
	}
	if (input::getInput()->getmouposX() >= 400 && input::getInput()->getmouposX() <= 500 && input::getInput()->getmouposY() >= 350 && input::getInput()->getmouposY() <= 450)
	{
		detail->setText("SETTING");
		detail->setSize(7);
		onButt = true;
		if (input::getInput()->getmousebutt(LEFT) == true)
		{
			gameinit::getG()->getGamestate()->pushState(new settingState());
		}
		return;
	}
	else {
		onButt = false;
	}
	if (input::getInput()->getmouposX() >= 600 && input::getInput()->getmouposX() <= 700 && input::getInput()->getmouposY() >= 350 && input::getInput()->getmouposY() <= 450)
	{
		detail->setText("RESTART");
		detail->setSize(7);
		onButt = true;
		if (input::getInput()->getmousebutt(LEFT) == true)
		{
			gameinit::getG()->getGamestate()->changeState(new countdownState());
		}
		return;//return vi neu ko return thi onbutt luon = false
	}
	else {
		onButt = false;
	}
	if (input::getInput()->getmouposX() >= 700 && input::getInput()->getmouposX() <= 800 && input::getInput()->getmouposY() >= 0 && input::getInput()->getmouposY() <=100)
	{
		detail->setText("EXIT");
		detail->setSize(4);
		onButt = true;
		if (input::getInput()->getmousebutt(LEFT) == true)
		{
			gameinit::getG()->quitSdl();
		}
		return;
	}
	else {
		onButt = false;
	}
}

void pauseState::render()
{
	for (int i = 0; i < 8; i++)
	{
		back[i].draw(gameinit::getG()->getRenderer());
	}
	if (onButt !=false)
	{
		detail->draw(100, 50);
	}
}

bool pauseState::onEnter()
{
	back[0].load(0, 0, 1157, 600, 0, 0, 1157, 600, "background", 1);
	back[0].setv(1);
	back[1].load(0, 0, 1157, 600, 0, 0, 1157, 600, "background", 1);
	back[1].setv(1);
	//back[2].loadimage("asset/ground.png", "ground1", gameinit::getG()->getRenderer());
	back[2].load(0, 0, 1100, 16, 0, 600 - 16, 1100, 16, "ground", 1);
	back[3].load(0, 0, 1100, 16, 0, 600 - 16, 1100, 16, "ground", 1);
	back[3].setv(2);
	back[2].setv(2);
	back[4].load(0, 0, 100, 100, 200, 350, 100, 100, "play", 1);
	back[5].load(0, 0, 128, 128, 400, 350, 100, 100, "setting", 1);
	back[6].load(0, 0, 200, 200, 600, 350, 100, 100, "restart", 1);
	back[7].load(0, 0, 100, 100, 700, 0, 100, 100, "exit", 1);
	return true;
}

bool pauseState::onExit()
{
	detail->clean();
	delete detail;
	return true;
}
