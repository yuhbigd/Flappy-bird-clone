#include "settingState.h"
#include"inputHandle.h"
void settingState::update()
{
	if (input::getInput()->getmousebutt(LEFT) == true)
	{
		if (input::getInput()->getmouposX() >= 162 && input::getInput()->getmouposX() <= 358
			&& input::getInput()->getmouposY() >= 425 && input::getInput()->getmouposY() <= 452)
		{
			changemusic();
		}
		if (input::getInput()->getmouposX() >= 162 && input::getInput()->getmouposX() <= 358
			&& input::getInput()->getmouposY() >= 225 && input::getInput()->getmouposY() <= 252)
		{
			changechunk();
		}
		if (input::getInput()->getmouposX() >= 0 && input::getInput()->getmouposX() <= 50
			&& input::getInput()->getmouposY() >=0&& input::getInput()->getmouposY() <= 50)
		{
			test2.setvolume(volumeMusic);
			gameinit::getG()->getGamestate()->popState();
		}
	}
	if (isrun == false&& input::getInput()->getmousebutt(LEFT) == false)
	{
		test2.setvolume(volumeMusic);
		isrun = true;
	}
	if (isrunchunk == false&& input::getInput()->getmousebutt(LEFT) == false)
	{
		test2.pausechunk();
		test.setvolume(volumeChunk);
		isrunchunk = true;
	}
	changeMuteicon();
}

void settingState::render()
{
	back.drawAll(gameinit::getG()->getRenderer());
	back1.drawDetail(gameinit::getG()->getRenderer());
	for (int i = 0; i < 2; i++)
	{
		sound[i].drawDetail(gameinit::getG()->getRenderer());
		bar[i].drawDetail(gameinit::getG()->getRenderer());
		circle[i].drawDetail(gameinit::getG()->getRenderer());
	}
	cC->draw(80, 170);
	sC->draw(80, 370);
}

bool settingState::onEnter()
{
	test.init("jump.wav");
	test2.init("flappy.mp3");
	back.load(0, 0, 1157, 600, "background", 0);
	sound[0].loadDetail(0, 0, 128, 128,80, 200,64, 64, "sound", 1);
	sound[1].loadDetail(0, 0, 128, 128,80, 400,64, 64, "sound", 1);
	bar[0].loadDetail(0, 0, 64, 64, 162, 232, double(volumeChunk / 128) * 200, 7, "bar", 1);
	bar[1].loadDetail(0, 0, 64, 64, 162, 432, double(volumeMusic / 128) * 200, 7, "bar", 1);
	circle[0].loadDetail(0, 0, 128, 128, 0, 232 - 14, 32, 32, "circle", 1);
	circle[0].setpos(double(volumeChunk / 128) * 200+162);
	circle[1].loadDetail(0, 0, 128, 128, 0, 432 - 14,32, 32, "circle", 1);
	circle[1].setpos(double(volumeMusic / 128) * 200+162);
	back1.loadDetail(0, 0, 128, 128, 0, 0, 50, 50, "back", 1);
	return true;
}
bool settingState::onExit()
{
	cC->clean();
	sC->clean();
	delete sC;
	delete cC;
	return true;
}

void settingState::changemusic()
{
	double a = double(input::getInput()->getmouposX() - 162) / 200 * 128;
	if (a > 115)
	{
		a = 128;
	}
	if (a < 5)
	{
		a = 0;
	}
	circle[1].setpos(input::getInput()->getmouposX()); 
	volumeMusic = a;
	bar[1].loadDetail(0, 0, 64, 64, 162, 432, double(a / 128) * 200, 7, "bar", 1);
	isrun = false;
}

void settingState::changechunk()
{
	double a = double(input::getInput()->getmouposX() - 162) / 200 * 128;
	if (a > 115)
	{
		a = 128;
	}
	if (a < 5)
	{
		a = 0;
	}
	circle[0].setpos(input::getInput()->getmouposX());
	volumeChunk = a;
	bar[0].loadDetail(0, 0, 64, 64, 162, 232, double(volumeChunk / 128) * 200, 7, "bar", 1);
	isrunchunk = false;
}

void settingState::changeMuteicon()
{
	if (largechunk == false && volumeChunk == 0)
	{
		sound[0].loadDetail(0, 0, 128, 128, 80, 200, 54, 54, "mute", 1);
		largechunk = true;
	}
	else if (largechunk == true && volumeChunk > 0)
	{
		sound[0].loadDetail(0, 0, 128, 128, 80, 200, 64, 64, "sound", 1);
		largechunk = false;
	}
	if (largemusic == false && volumeMusic == 0)
	{
		sound[1].loadDetail(0, 0, 128, 128, 80, 400, 54, 54, "mute", 1);
		largemusic = true;
	}
	else if (largemusic == true && volumeMusic > 0)
	{
		sound[1].loadDetail(0, 0, 128, 128, 80, 400, 64, 64, "sound", 1);
		largemusic = false;
	}
}