#include "PIPE.h"
void pipe::load(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame)
{
	x = 800;//vi tri ban dau dang sau man hinh
	y = 200 + rand() % (400);//max 600
	gameobject::load(x_image, y_image, image_width, image_height, x, y, width, height, ID, frame);
}

void pipe::loadimage(string filename, string id, SDL_Renderer* renderer)
{
	gameobject::loadimage(filename, id, renderer);
}

void pipe::draw(SDL_Renderer* renderer)
{
       gameobject::draw(renderer);
}

void pipe::drawimageflip(SDL_Renderer* renderer)
{
	imageManage::getImage()->drawangle(this->ID, pos_img.getx(), pos_img.gety(), img_w, img_h, pos.getx(), pos.gety(), obj_width, obj_height, renderer, curr_frame,180);//ve nguoc voi hinh ban dau
}
void pipe::updateimage()
{
	pos.setx(pos.getx()-4);//di chuyen ve phia sau 
}
