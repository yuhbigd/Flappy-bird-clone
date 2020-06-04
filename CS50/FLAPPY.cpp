#include "FLAPPY.h"
#include"inputHandle.h"
int GRAVITY = 4;
void bird::load(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame)
{
	gameobject::load(x_image, y_image, image_width, image_height, x, y, width, height, ID, frame);
}
void bird::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	gameobject::loadimage(filename, id, renderer);
}

void bird::draw(SDL_Renderer* renderer)
{
	gameobject::draw(renderer);
}
//gia tao trong luc dung ben tre 1 luc roi roi nhanh dan dan gia toc g=0.5 v=gt ,s+=0+v
void bird::updateimage()
{
	
	if (input::getInput()->getkeybutt(_SPACE_) == true)
	{
		acceleration.sety(0);
		veclocity.sety(-6);//tao ra cach di kieu len xuong tao kho khan cho nguoi choi
	}
	else {
		acceleration.sety(0.6);
	}
	if (acceleration.gety() >= GRAVITY)
	{
		acceleration.sety(GRAVITY);//>4 thi bang 4 a=4 tranh truong hop roi qua nhanh khong the kiem soat
	}
	veclocity = veclocity + acceleration;
	pos = pos + veclocity;
}

void bird::drawangle(SDL_Renderer* renderer,double angle)
{
	imageManage::getImage()->drawangle(this->ID, pos_img.getx(), pos_img.gety(), img_w, img_h, pos.getx(), pos.gety(), obj_width, obj_height, renderer, curr_frame, angle); //ve con chim nghieng
}


