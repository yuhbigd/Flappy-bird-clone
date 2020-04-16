#ifndef __background__
#define __background__
#include"gameobj.h"
class Background :public gameobject
{
public:
	Background() :gameobject()
	{
	}
	void load(int x, int y, int width, int height, string ID, int frame);
	void loadimage(string filename, string id, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
	void updateimage();
	void setv(int a)
	{
		veclocity.setx(-a);
	}
	void setpos(int a)
	{
		pos.setx(a);
	}
	int getposx();
	int getposy();
};
#endif // !__background__
