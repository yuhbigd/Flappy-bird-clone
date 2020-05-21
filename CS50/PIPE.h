#ifndef _PIPE_
#define _PIPE_
#include"gameobj.h"
#include<cstdlib>//rand
class pipe:public gameobject
{
private:
	int gapk ;
public:
	pipe() 
	{
		gapk = 200;
	}
	void load(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame);
	void loadimage(string filename, string id, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
	void drawimageflip( SDL_Renderer* renderer);
	void updateimage();
	int getposx()
	{
		return pos.getx();
	}
	double getpospipey()
	{
		return pos.gety();
	}
	void setposy()
	{
		pos.sety(200 + rand() % (400));
	}
	void setgapk(int n)
	{
		gapk = n;
	}
	void setposyforup(double a)
	{
		pos.sety(a - gapk-obj_height);
	}
};
#endif // !_PIPE_