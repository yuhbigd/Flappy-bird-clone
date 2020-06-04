#ifndef PLAY__
#define PLAY__
#include"Gamestate.h"
#include<vector>
#include"PIPE.h"
#include"FILETEXT.h"
#include"gameoverstate.h"
#include"FLAPPY.h"
#include"BackGround.h"
#include"chunkeffect.h"

class playState : public GameState
{
public:
	 void update();
	 void render();

	bool onEnter();
	 bool onExit();
 std::string getStateId() const { return menuId; }

private:
	Background* back = new Background[4];
	bool collideforlow(pipe a);//va cham cot tren
	bool collideforup(pipe a);//va cham cot duoi
	vector<pair<pipe, pipe>> pairpipe;//cap 2 cot 1 luc
	bool birdcolli = true;//trang thai song cua chim
	bird birdy;//chim
	string menuId;
	textt* scored = new textt(20, "0");
	chunkeff explosion;
	chunkeff jump;
	bool afterSetting;

	int timer = 0;//t sinh cot
	pipe a, b;
	int score = 0;
};

#endif // !MENU__

