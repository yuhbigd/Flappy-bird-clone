#include "BackGround.h"

void Background::load(int x, int y, int width, int height, string ID, int frame)
{
	gameobject::load(x, y, width, height, ID, frame);
}

void Background::loadDetail(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame)
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

void Background::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	gameobject::loadimage(filename, id, renderer);
}

void Background::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}

void Background::drawAll(SDL_Renderer* renderer)
{
	imageManage::getImage()->drawAllwindow(renderer, ID);
}

void Background::drawDetail(SDL_Renderer* renderer)
{
	imageManage::getImage()->drawDetail(this->ID, pos_img.getx(), pos_img.gety(), img_w, img_h, pos.getx(), pos.gety(), obj_width, obj_height, renderer,1);
}

void Background::updateimage()
{
	pos = pos + veclocity;
	if (pos.getx() < -obj_width)
	{
		pos.setx(0);
	}
}

int Background::getposx()
{
	return gameobject::getposx();
}

int Background::getposy()
{
	return pos.gety();
}
