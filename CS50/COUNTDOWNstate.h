#ifndef COUNT__
#define COUNT__
#include"Gamestate.h"
#include"BackGround.h"
#include"playstate.h"
class countdownState : public GameState
{
public:
 void update();
 void render();

 bool onEnter();
 bool onExit();
 
private:
	Background back[4];
	textt *count0=new textt(60,"1");	
	textt *count1=new textt(60,"2");	
	textt *count2=new textt(60,"3");
};

#endif // !COUT__

