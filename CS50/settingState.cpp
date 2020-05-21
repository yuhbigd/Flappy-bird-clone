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
			tValue();
		}
		if (input::getInput()->getmouposX() >= 162 && input::getInput()->getmouposX() <= 358
			&& input::getInput()->getmouposY() >= 225 && input::getInput()->getmouposY() <= 252)
		{
			changechunk();
			tValue();
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
	back.draw(gameinit::getG()->getRenderer());
	back1.draw(gameinit::getG()->getRenderer());
	for (int i = 0; i < 2; i++)
	{
		sound[i].draw(gameinit::getG()->getRenderer());
		bar[i].draw(gameinit::getG()->getRenderer());
		circle[i].draw(gameinit::getG()->getRenderer());
	}
	cC->draw(80, 170);
	sC->draw(80, 370);
	soundValue->draw(400, 420);
	chunkValue->draw(400, 220);
}


bool settingState::onEnter()
{
	test.init("jump.wav");
	test2.init("flappy.mp3");
	back.load(0, 0, 1157, 600, 0, 0, 1157, 600, "background", 1);
	sound[0].load(0, 0, 128, 128,80, 200,64, 64, "sound", 1);
	sound[1].load(0, 0, 128, 128,80, 400,64, 64, "sound", 1);
	bar[0].load(0, 0, 64, 64, 162, 232, double(volumeChunk / 128) * 200, 7, "bar", 1);
	bar[1].load(0, 0, 64, 64, 162, 432, double(volumeMusic / 128) * 200, 7, "bar", 1);
	circle[0].load(0, 0, 128, 128, 0, 232 - 14, 32, 32, "circle", 1);
	circle[0].setpos(double(volumeChunk / 128) * 200+162);
	circle[1].load(0, 0, 128, 128, 0, 432 - 14,32, 32, "circle", 1);
	circle[1].setpos(double(volumeMusic / 128) * 200+162);
	back1.load(0, 0, 128, 128, 0, 0, 50, 50, "back", 1);
	tValue();
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
	bar[1].load(0, 0, 64, 64, 162, 432, double(a / 128) * 200, 7, "bar", 1);
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
	bar[0].load(0, 0, 64, 64, 162, 232, double(volumeChunk / 128) * 200, 7, "bar", 1);
	isrunchunk = false;
}

void settingState::changeMuteicon()
{
	if (largechunk == false && volumeChunk == 0)
	{
		sound[0].load(0, 0, 128, 128, 80, 200, 54, 54, "mute", 1);
		largechunk = true;
	}
	else if (largechunk == true && volumeChunk > 0)
	{
		sound[0].load(0, 0, 128, 128, 80, 200, 64, 64, "sound", 1);
		largechunk = false;
	}
	if (largemusic == false && volumeMusic == 0)
	{
		sound[1].load(0, 0, 128, 128, 80, 400, 54, 54, "mute", 1);
		largemusic = true;
	}
	else if (largemusic == true && volumeMusic > 0)
	{
		sound[1].load(0, 0, 128, 128, 80, 400, 64, 64, "sound", 1);
		largemusic = false;
	}
}

void settingState::tValue()
{
	int a = volumeChunk;
	int b = volumeMusic;
	if (volumeChunk == 0)
	{
		a = 1;
	}
	if (volumeMusic == 0)
	{
		b = 1;
	}
	int numOc = log10(a);
	chunkValue->setText(to_string(int(volumeChunk)));
	chunkValue->setSize(numOc + 1);
	int numOm = log10(b);
	soundValue->setText(to_string(int (volumeMusic)));
	soundValue->setSize(numOm + 1);
}
