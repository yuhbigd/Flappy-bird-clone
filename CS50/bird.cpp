#include "bird.h"
int GRAVITY = 2;

void player::load(int x, int y, int width, int height, string ID, int frame)
{
	gameobject::load(x, y, width, height, ID, frame);
}

void player::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	gameobject::loadimage(filename, id, renderer);
}

void player::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}

void player::update()
{
	
}
