#ifndef __TEXT__
#define __TEXT__
#include <SDL.h>
#include"CS50.h"
#include <SDL_ttf.h>
#include<iostream>
#include <string>
using namespace std;
class textt
{
private:
	SDL_Texture* _textTexture;
	 SDL_Rect _textRect;

	string _fontPath;
	string _fontValue;
	int _fontSize;
	SDL_Color _fontColor;
public:
	textt(int fontsize, string text);
	~textt();
	SDL_Texture* loadFont(string fontPath, int fontSize, string text, const SDL_Color& color);
	void draw(int x, int y);
	void setText(string newText);
	void clean()
	{
		SDL_DestroyTexture(_textTexture);
	}
};
#endif // !__TEXT__

