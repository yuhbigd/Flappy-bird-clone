#ifndef __OBJ__
#define __OBJ__
#include<iostream>
#include"V2D.h"
#include<SDL.h>
#include"texturemanage.h"
using namespace std;

class gameobject
{
protected:
	string ID;

	int curr_frame;
	//int curr_row;
	int obj_width;
	int obj_height;
	vec2D pos_img;//x y trong anh
	int img_w;//do rong
	int img_h;//do cao trong anh

	vec2D pos;
	vec2D veclocity;
	vec2D acceleration;
public:
	gameobject()
	{
		curr_frame = 0;
		obj_width = 0;
		obj_height = 0;
		pos.setx(0);
		pos.sety(0);
		veclocity.setx(0);
		veclocity.sety(0);
		acceleration.setx(0);
		acceleration.sety(0);
	}
	virtual void loadimage(string filename, string id, SDL_Renderer* renderer);
	virtual  void load(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame);
	virtual void draw(SDL_Renderer* renderer);
	virtual void updateimage();
	virtual int getposx()
	{
		return pos.getx();
	}

};
#endif // !__OBJ__