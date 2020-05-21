#include "texturemanage.h"
imageManage* imageManage::instance = 0;
void imageManage::load(string filename, string id, SDL_Renderer* renderer)
{
	 SDL_Surface *tempSurface= IMG_Load(filename.c_str());
	 if (tempSurface == 0)
	 {
		 cout << "No image in folder " << endl;
		 return;
	}
	 SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, tempSurface);
	 SDL_FreeSurface(tempSurface);
	 tempSurface = NULL;
	 if (text != 0)
	 {
		 textureHolder[id] = text;
		 return;
	 }
	
	 cout << filename << endl;
	 cout << "NO TEXTURE" << endl;
	 return;
}
//x:vi tri x tren man y:vitri y tren man, width: do rong cua anh ,height
//2 ham luon la lay ca anh 
void imageManage::drawangle(string id, int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, SDL_Renderer* renderer, int frame, double angle, SDL_RendererFlip flip)
{
	sourceRectangle.x = x_image * frame;
	sourceRectangle.y = y_image;
	sourceRectangle.w = image_width;
	sourceRectangle.h = image_height;
	posRectangle.x = x;
	posRectangle.y = y;
	posRectangle.w = width;
	posRectangle.h = height;
	SDL_RenderCopyEx(renderer, textureHolder[id], &sourceRectangle, &posRectangle,angle,0, flip);
}

void imageManage::drawDetail(string id, int x_image, int y_image, int image_width, int image_height, int x, int y, int width, int height, SDL_Renderer* renderer, int frame)
{
	sourceRectangle.x = x_image*frame;
	sourceRectangle.y = y_image;
	sourceRectangle.w = image_width;
	sourceRectangle.h = image_height;
	posRectangle.x = x;
	posRectangle.y = y;
	posRectangle.w = width;
	posRectangle.h = height;
	SDL_RenderCopy(renderer, textureHolder[id], &sourceRectangle, &posRectangle);
}
