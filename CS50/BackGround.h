#ifndef __background__
#define __background__
#include"gameobj.h"
class Background :public gameobject
{
private:
	vec2D pos_img;//x y trong anh
	int img_w;//do rong
	int img_h;//do cao trong anh
public:
	Background() :gameobject()
	{
		img_w = 0;
		img_h = 0;
	}
	//x,y_image: vi tri lay anh, image_width,height:do rong can lay tu x va y x,y,w,h inra mh
	void load(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame);
	void loadimage(string filename, string id, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
	void updateimage();
	void setv(int a)//van toc
	{
		veclocity.setx(-a);
	}
	void setpos(int a)
	{
		pos.setx(a);
	}
	int getposx();
	int getposy();
};
#endif // !__background__
