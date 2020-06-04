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
	int size;
	SDL_Color _fontColor;
public:
	textt()
	{
		_textTexture = NULL;
		_fontPath = "";
		_fontValue = "";
		_fontSize = 0;
		size = 0;
		_fontColor = { 255,255,255,255 };
	}
	textt(int fontsize, string text);
	~textt();
	SDL_Texture* loadFont(string fontPath, int fontSize, string text, const SDL_Color& color);
	void draw(int x, int y);
	void setText(string newText);
	void setSize(int n)//n la so cac tu
	{
		if (size != n)
		{
			if (size == 0)
			{
				_textRect.w = (_textRect.w / 1) * n;
			}
			else {
				_textRect.w = (_textRect.w / size) * n;
			}
			_textTexture = loadFont(_fontPath, _fontSize, _fontValue, _fontColor);
			size = n;
		}
		else {
			return;
		}
		
	}
	void clean()
	{
		SDL_DestroyTexture(_textTexture);
	}
	void setcolorer(SDL_Color color)
	{
		this->_fontColor = color;
		_textTexture = loadFont(_fontPath, _fontSize, _fontValue, _fontColor);
	}
};
#endif // !__TEXT__

