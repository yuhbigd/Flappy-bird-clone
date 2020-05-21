#ifndef _FLAPPY_
#define _FLAPPY_
#include"gameobj.h"
class bird:public gameobject
{
public:
	bird():gameobject()
	{
	}
	void load(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame);
	void loadimage(string filename, string id, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
	void drawangle(SDL_Renderer* renderer,double angle);
	void updateimage();
	int getposy()
	{
		return pos.gety();
	}
	void set(double x, double y)
	{
		pos.setx(x);
		pos.sety(y);
	}
};
#endif // !_FLAPPY_
