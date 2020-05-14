#include "gameoverstate.h"
#include "MENUSTATE.h"
#include "CS50.h"
#include"inputHandle.h"
#include"MENUSTATE.h"
void gamoverState::update()
{
	back[1].setpos(back[0].getposx() + 1156);
	back[3].setpos(back[2].getposx() + 1100);
	for (int i = 0; i < 7; i++)
	{
		back[i].updateimage();
	}
	if (input::getInput()->getmousebutt(LEFT) == true)
	{
		if (input::getInput()->getmouposX() >= 700 && input::getInput()->getmouposX() <= 800
			&& input::getInput()->getmouposY() >= 0 && input::getInput()->getmouposY() <= 100)
		{
			gameinit::getG()->quitSdl();
		}
		if (input::getInput()->getmouposX() >= 200 && input::getInput()->getmouposX() <= 400
			&& input::getInput()->getmouposY() >= 400 && input::getInput()->getmouposY() <= 600)
		{
			mBack.pausechunk();
			gameinit::getG()->getGamestate()->changeState(new countdownState());
		}
		if (input::getInput()->getmouposX() >= 400 && input::getInput()->getmouposX() <= 600
			&& input::getInput()->getmouposY() >= 400 && input::getInput()->getmouposY() <= 600)
		{
			mBack.pausechunk();
			gameinit::getG()->getGamestate()->changeState(new MenuState());
		}
	}
}
void gamoverState::render()
{
	for (int i = 0; i < 7; i++)
	{
		back[i].draw(gameinit::getG()->getRenderer());
	}
	ysc->draw(0, 100);
	score->draw(390,108);
	hsc->draw(0, 220);
	hightscore->draw(525, 228);
}
bool gamoverState::onEnter()
{
	back[0].load(0, 0, 1157, 600, "background", 0);
	back[0].setv(1);
	back[1].load(0, 0, 1157, 600, "background", 0);
	back[1].setv(1);
	back[2].load(0, 600 - 16, 1100, 16, "ground", 0);
	back[3].load(0, 600 - 16, 1100, 16, "ground", 0);
	back[3].setv(2);
	back[2].setv(2);
	back[4].load(700, 0, 100, 100, "exit", 0);
	back[4].setv(0);
	back[6].load(200, 400, 200, 200, "restart", 0);
	back[6].setv(0);
	back[5].load(400, 400, 200, 200, "menu", 0);
	back[5].setv(0);
	ifstream file1, file2;
	ofstream file3;
	file1.open("score.txt");
	file1 >> yscore;
	file2.open("hightscore.txt");
	file2 >> hscore;
	if (yscore > hscore)
	{
		file3.open("hightscore.txt");
		file3 << yscore;
		hsc->setText("N HIGHTEST SCORE: ");
		hscore = yscore;
	}
	score->setText(to_string(yscore));
	score->setSize(yscore / 10 + 1);
	hightscore->setText(to_string(hscore));
	hightscore->setSize(hscore / 10 + 1);
	mBack.init("flappy.mp3");
	mBack.playmusic();
	return true;
}

bool gamoverState::onExit()
{
	hsc->clean();
	ysc->clean();
	score->clean();
	hightscore->clean();
	return true;
}
