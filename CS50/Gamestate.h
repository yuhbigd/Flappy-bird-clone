#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include<string>

class GameState//abstract class de tien cho viec chuyen doi o gamestatemachine
{
public:
	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual ~GameState() {}
};

#endif