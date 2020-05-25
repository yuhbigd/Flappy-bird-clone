#ifndef _IPHANDLE_
#define _IPHANDLE_
#include<SDL.h>
#include<vector>
#include<iostream>
#include"CS50.h"
using namespace std;
enum MOUSEBUTT
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};
enum KEYBUTTON
{
	_ESC_ = 0,
   _SPACE_ = 1,
   _V_=2
};
class input
{
private:
	static input* inputinstance;
	vector<bool> mousebutt;
	vector<bool> keybutt;
	int x = 0;
	int y = 0;
	input()
	{
		for (int i = 0; i < 3; i++)
		{
			mousebutt.push_back(false);
		}
		for (int i = 0; i < 3; i++)
		{
			keybutt.push_back(false);
		}
	}
	~input()
	{
		delete inputinstance;
	}
public:
	int getmouposX()
	{
		return x;
	}
	int getmouposY()
	{
		return y;
	}
	static input* getInput()
	{
		if (inputinstance == 0)
		{
			inputinstance = new input();
		}
		return inputinstance;
	}
	bool getmousebutt(int index)
	{
		return mousebutt[index];
	}
	bool getkeybutt(int index)
	{
		return keybutt[index];
	}
	void update();
};
#endif // !_IPHANDLE_

