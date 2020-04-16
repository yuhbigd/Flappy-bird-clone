#ifndef __GAMESTATEMACHINE_H__
#define __GAMESTATEMACHINE_H__

#include<vector>
#include"GameState.h"
using namespace std;
class GameStateMachine
{
public:

	int axxx;
	void update();
	void render();
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

private:
	vector<GameState*> states;
};

#endif