#include "BackGround.h"
void Background::load(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame)
{
	gameobject::load(x_image, y_image, image_width, image_height, x, y, width, height, ID, frame);
}

void Background::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	gameobject::loadimage(filename, id, renderer);
}

void Background::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}

void Background::updateimage()
{
	pos = pos + veclocity;
	if (pos.getx() < -obj_width)//neu di qua -do rong cua anh thi set vt =0
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
