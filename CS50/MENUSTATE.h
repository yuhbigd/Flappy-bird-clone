#ifndef MENU__
#define MENU__
#include"Gamestate.h"
#include<vector>
#include"FILETEXT.h"
#include"musiceffect.h"
#include"BackGround.h"

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

private:
	      musiceff mBack;
		  Background back[8];
		  Background setting;
		  textt *c=new textt(60,"FLAPPY BIRD CLONE"); 	  
};

#endif // !MENU__

