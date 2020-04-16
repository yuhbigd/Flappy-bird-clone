#include "gameobj.h"

void gameobject::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	imageManage::getImage()->load(filename, id, renderer);
}

void gameobject::load(int x, int y, int width, int height, string ID, int frame)
{
	curr_frame = frame;
	obj_width = width;
	obj_height = height;
	this->ID = ID;
	pos.setx(x);
	pos.sety(y);
}

void gameobject::draw(SDL_Renderer* renderer)
{
	imageManage::getImage()->drawwithframe(ID,pos.getx(), pos.gety(), obj_width, obj_height, renderer, curr_frame);
}

void gameobject::updateimage()
{
	curr_frame = 0;
}
