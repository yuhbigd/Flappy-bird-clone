#include "FLAPPY.h"
#include"inputHandle.h"
int GRAVITY = 3;
void bird::load(int x, int y, int width, int height, string ID, int frame)
{
	gameobject::load(x, y, width, height, ID, frame);
}

void bird::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	gameobject::loadimage(filename, id, renderer);
}

void bird::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}
//gia tao trong luc dung ben tre 1 luc roi roi nhanh dan dan gia toc g=0.5 v=gt 
void bird::updateimage()
{
	
	if (input::getInput()->getkeybutt(_SPACE_) == true)
	{
		acceleration.sety(0);
		veclocity.sety(-5);//len nhanh ko gia toc
	}
	else {
		acceleration.sety(0.5);
	}
	if (acceleration.gety() >= GRAVITY)
	{
		acceleration.sety(GRAVITY);//>3 thi bang 3 a=3
	}
	veclocity = veclocity + acceleration;
	pos = pos + veclocity;
}

void bird::drawangle(SDL_Renderer* renderer,double angle)
{
	imageManage::getImage()->drawangle(ID, pos.getx(), pos.gety(), obj_width, obj_height, renderer, curr_frame,angle);
}


