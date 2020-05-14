#include "FILETEXT.h"
textt::textt(int fontsize, string text)
{
	_fontColor = { 255, 255, 255, 255 };
	_fontPath = "flappy.ttf";
	_fontSize = fontsize;
	_fontValue = text;
	_textTexture = loadFont(_fontPath, _fontSize, _fontValue, _fontColor);
	SDL_QueryTexture(_textTexture, NULL, NULL, &_textRect.w, &_textRect.h);
}

textt::~textt()
{
}

SDL_Texture* textt::loadFont(string fontPath, int fontSize, string text, const SDL_Color& color)
{
	TTF_Init(); 
	TTF_Font* font = NULL;
   font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (!font)
	{
		cout<<"Error loading font. Error: "<< TTF_GetError()<<endl;
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (!textSurface)
	{
		cout<<"Error creating text surface: "<< SDL_GetError()<<endl;
	}

	SDL_Texture* Texture = SDL_CreateTextureFromSurface(gameinit::getG()->getRenderer(), textSurface);

	SDL_FreeSurface(textSurface);

	TTF_CloseFont(font);

	return Texture;
}

void textt::draw(int x, int y)
{
	_textRect.x = x;
	_textRect.y = y;
	SDL_RenderCopy(gameinit::getG()->getRenderer(), _textTexture, 0, &_textRect);
}

void textt::setText(string newText)
{
	if (newText == _fontValue)
	{
		return;
	}
	_fontValue = newText;
	_textTexture = loadFont(_fontPath, _fontSize, _fontValue, _fontColor);
}
