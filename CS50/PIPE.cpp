#include "PIPE.h"

void pipe::load(int x, int y, int width, int height, string ID, int frame)
{
	x = 800;
	y = 200+ rand() % (375);
	curr_frame = frame;
	obj_width = width;
	obj_height = height;
	this->ID = ID;
	pos.setx(x);
	pos.sety(y);
}

void pipe::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	imageManage::getImage()->load(filename, id, renderer);
}

void pipe::draw(SDL_Renderer* renderer)
{
	imageManage::getImage()->drawwithframe(ID, pos.getx(), pos.gety(), obj_width, obj_height, renderer, curr_frame);
}

void pipe::drawimageflip(SDL_Renderer* renderer)
{
	imageManage::getImage()->drawwithframe(ID, pos.getx(), pos.gety(), obj_width, obj_height, renderer, curr_frame, SDL_FLIP_VERTICAL);
}
void pipe::updateimage()
{
	pos.setx(pos.getx()-4);
}
