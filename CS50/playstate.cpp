#include "playstate.h"
#include"CS50.h"
#include"MENUSTATE.h"
#include"string"
#include"fstream"
#include"inputHandle.h"
using namespace std;
void playState::update()
{
	if (birdcolli == true)
	{
		back[1].setpos(back[0].getposx() + 1156);//background
		back[3].setpos(back[2].getposx() + 1100);//ground
		for (int i = 0; i < 4; i++)
		{
			back[i].updateimage();
		}
		birdy.updateimage();
		for (int i = 1; i < pairpipe.size(); i++)
		{
			if (birdy.getposx() + 18 == pairpipe[i].first.getposx() + 70)
			{
				score++;
				fstream file;
				file.open("score.txt", ios::out);
				file << score;
				jump.playmusic();
				if (score >= 10)
				{
					oldSize = newSize;
					newSize = int(log10(score));
					if (newSize > oldSize)
					{
						scored->setSize(newSize + 1);
					}
				}
				scored->setText(to_string(score));
			}
			birdcolli = collideforup(pairpipe[i].second);
			if (birdcolli == false)
			{
				break;
			}
			birdcolli = collideforlow(pairpipe[i].first);
			if (birdcolli == false)
			{
				break;
			}
			pairpipe[i].first.updateimage();
			pairpipe[i].second.updateimage();
			if (pairpipe[i].first.getposx() < -72)
			{
				pairpipe.erase(pairpipe.begin() + i);
			}
		}
	}
	else {
		explosion.playmusic();
		gameinit::getG()->getGamestate()->changeState(new gamoverState());
	}
}

void playState::render()
{
	timer++;
	for (int i = 0; i < 2; i++)
	{
		back[i].draw(gameinit::getG()->getRenderer());
	}
	if (input::getInput()->getkeybutt(_SPACE_) == true)
	{
    birdy.drawangle(gameinit::getG()->getRenderer(),-15);
	}
	else {
		birdy2.set(birdy.getposx(), birdy.getposy());
		birdy2.drawangle(gameinit::getG()->getRenderer(),15);
	}
	if (timer > 75)
	{
		a.setposy();
		if (score > 10)
		{
			b.setgapk(130);
		}
		b.setposyforup(a.getpospipey());
		pairpipe.push_back(make_pair(a, b));
		timer = 0;
	}

	for (int i = 0; i < pairpipe.size(); i++)
	{
		pairpipe[i].first.draw(gameinit::getG()->getRenderer());
		pairpipe[i].second.drawimageflip(gameinit::getG()->getRenderer());
	}
	scored->draw(400, 20);
	for (int i = 2; i < 4; i++)
	{
		back[i].draw(gameinit::getG()->getRenderer());
	}

}

bool playState::onEnter()
{
	//back[0].loadimage("asset/background.png", "background", gameinit::getG()->getRenderer());
	back[0].load(0, 0, 1157, 600, "background", 0);
	back[0].setv(1);
	back[1].load(0, 0, 1157, 600, "background", 0);
	back[1].setv(1);
	//back[2].loadimage("asset/ground.png", "ground", gameinit::getG()->getRenderer());
	back[2].load(0, 600 - 16, 1100, 16, "ground", 0);
	back[3].load(0, 600 - 16, 1100, 16, "ground", 0);
	back[3].setv(2);
	back[2].setv(2);
	birdy.load(400, 300, 36, 24, "bird", 0);
	birdy2.load(400, 300, 36, 24, "birddown", 0);
	int a1 = 0, b1 = 0;
	a.load(a1, b1, 70, 400, "pipe", 0);
	b.load(a1, b1, 70, 600, "pipe", 0);
	b.setposyforup(a.getpospipey());
	pairpipe.push_back(make_pair(a, b));
	fstream file;
	file.open("score.txt", ios::out);
	file << score;
	explosion.init("explosion.wav");
	jump.init("jump.wav");
	return true;
}

bool playState::onExit()
{
	scored->clean();
	return true;
}
//posy+height of bird
bool playState::collideforlow(pipe a)
{
	if ((birdy.getposx() + 18 >= a.getposx()) && (birdy.getposx() + 18 <= (a.getposx() + 70)) && birdy.getposy() + 24 >= a.getpospipey())
	{
		return false;
	}
	if ((birdy.getposx() + 30 >= a.getposx()) && (birdy.getposx() + 18 <= (a.getposx() + 70)) && birdy.getposy() + 24 >= a.getpospipey())
	{
		return false;
	}
	if (birdy.getposy() + 16 >= 600 - 25)
	{
		return false;
	}
	return true;
}
//x+16 de chim ra giua,ygiu nguyen khonag tu pipx->pipxwidth 
bool playState::collideforup(pipe a)
{
	if ((birdy.getposx() + 18 >= a.getposx()) && (birdy.getposx() + 18 <= (a.getposx() + 70)) && birdy.getposy() <= a.getpospipey() + 600)
	{
		return false;
	}
	if ((birdy.getposx() + 30 >= a.getposx()) && (birdy.getposx() + 18 <= (a.getposx() + 70)) && birdy.getposy() <= a.getpospipey() + 600)
	{
		return false;
	}
	return true;
}

