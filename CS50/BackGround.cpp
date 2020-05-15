#include "BackGround.h"

void Background::load(int x, int y, int width, int height, string ID, int frame)
{
	gameobject::load(x, y, width, height, ID, frame);
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
