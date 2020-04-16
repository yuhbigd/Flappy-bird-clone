#include "gamestatemachine.h"

void GameStateMachine::update()
{
	if (states.empty())
	{
		return;
	}
	states.back()->update();
}

void GameStateMachine::render()
{
	if (!states.empty())
	{
		states.back()->render();
	}
}

void GameStateMachine::pushState(GameState* pState)
{
	states.push_back(pState);
	pState->onEnter();
}

void GameStateMachine::changeState(GameState* pState)
{
	if (!states.empty())
	{
		if (states.back() == pState)
		{
			return;
		}
		popState();
	}
	states.push_back(pState);
	states.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (states.empty())
	{
		return;
	}
	if (states.back()->onExit())
	{
		delete states.back();
		states.pop_back();
	}
}
