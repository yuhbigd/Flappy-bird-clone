#ifndef  _GAMEOVER_
#define _GAMEOVER_
#include"Gamestate.h"
#include<vector>
#include"COUNTDOWNstate.h"
#include"FILETEXT.h"
#include<fstream>
#include"musiceffect.h"
#include"BackGround.h"

class gamoverState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

private:
	Background back[7];
	textt* c = new textt(60, "GAME OVER");
	textt* score = new textt(50, "0");
	textt* ysc = new textt (60, "YOUR SCORE : ");
	textt* hsc = new textt(60, "HIGHTEST SCORE : ");
	textt* hightscore= new textt(50, "0");
	int yscore;
	int hscore;
	musiceff mBack;
};
#endif // ! _GAMEOVER_

