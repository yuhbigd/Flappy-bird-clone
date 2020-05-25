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
 countdownState()
 {
	 a = 0;
	 count0 = new textt(60, "1");
	 count1 = new textt(60, "2");
	 count2 = new textt(60, "3");
	 ispause = false;
 }
 countdownState(bool check)
 {
	 ispause = check;
	 a = 0;
	 count0 = new textt(60, "1");
	 count1 = new textt(60, "2");
	 count2 = new textt(60, "3");
 }
private:
	int a;//count time
	bool ispause;
	Background back[4];
	textt* count0;
	textt* count1;
	textt* count2;
};

#endif // !COUT__

