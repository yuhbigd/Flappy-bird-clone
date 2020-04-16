#ifndef _BIRD_
#define _BIRD_
#include"gameobj.h"
#include"inputHandle.h"
class player :public gameobject
{
public:
	void load(int x, int y, int width, int height, string ID, int frame);
	void loadimage(string filename, string id, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
	void update();
};
#endif // !_BIRD_

