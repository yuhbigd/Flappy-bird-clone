#ifndef _TXT_H_
#define _TXT_H_
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include<map>
using namespace std;

class imageManage
{
protected:
	map<string, SDL_Texture*> textureHolder;
	static imageManage* instance;
	SDL_Rect sourceRectangle;//dung de xac dinh phan anh tu anh e in len man
	SDL_Rect posRectangle;//dung de xa dinhj vi tri ma anh dc in ra
public:
	SDL_Texture* textxure(string id)
	{
		return textureHolder[id];
	}
	void eraseID(string ID)
	{
		textureHolder.erase(ID);
	}
	imageManage()
	{

	}

	static imageManage* getImage()
	{
		if (instance == 0)
		{
			instance = new imageManage();
		}
		return instance;
	}
	void load(string filename, string id, SDL_Renderer* renderer);
	void drawwithframe(string id, int x, int y, int width, int height, SDL_Renderer* renderer, int frame=0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawangle(string id, int x, int y, int width, int height, SDL_Renderer* renderer, int frame ,double angle ,SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawAllwindow(SDL_Renderer*renderer,string id)
	{
		SDL_RenderCopy(renderer, textureHolder[id], 0, 0);
	}
};
#endif // !_TXT_H_

