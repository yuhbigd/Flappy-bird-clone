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
	void load(int x, int y, int width, int height, string ID, int frame);//cho anh khong can lam j nhieu
	void loadDetail(int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, string ID, int frame);
	void loadimage(string filename, string id, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
	void drawAll(SDL_Renderer* renderer);
	void drawDetail(SDL_Renderer* renderer);
	void updateimage();
	void setv(int a)
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
