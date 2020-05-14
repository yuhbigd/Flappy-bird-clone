#ifndef _PIPE_
#define _PIPE_
#include"gameobj.h"
#include<cstdlib>//rand
class pipe 
{
private:
	string ID;

	int curr_frame;
	int obj_width;
	int obj_height;
	int gapk =300;
	vec2D pos;
public:
	pipe() 
	{
		curr_frame = 0;
		obj_width = 0;
		obj_height = 0;
		pos.setx(0);
		pos.sety(0);
	}
	void load (int x, int y, int width, int height, string ID, int frame);
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