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
	bool collideforlow(pipe a);
	bool collideforup(pipe a);
	vector<pair<pipe, pipe>> pairpipe;
	bool birdcolli = true;
	bird birdy,birdy2;
	string menuId;
	textt* scored = new textt(20, "0");
	chunkeff jump;
	chunkeff explosion;
};

#endif // !MENU__
