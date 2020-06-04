#include "gameobj.h"

void gameobject::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	imageManage::getImage()->load(filename, id, renderer);
}

void gameobject::load(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame)
{
	curr_frame = frame;
	obj_width = width;
	obj_height = height;
	this->ID = ID;
	pos.setx(x);
	pos.sety(y);
	pos_img.setx(x_image);
	pos_img.sety(y_image);
	img_w = image_width;
	img_h = image_height;
}


void gameobject::draw(SDL_Renderer* renderer)
{
	imageManage::getImage()->drawDetail(this->ID, pos_img.getx(), pos_img.gety(), img_w, img_h, pos.getx(), pos.gety(), obj_width, obj_height, renderer,curr_frame);
}

void gameobject::updateimage()
{
	curr_frame = 1;
}
