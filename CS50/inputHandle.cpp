#include"inputHandle.h"
input* input::inputinstance = 0;
void input::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			gameinit::getG()->setrun(false);
			break;
		}
		if (e.type == SDL_MOUSEMOTION)
		{
			this->x = e.motion.x;
			this->y = e.motion.y;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				mousebutt[LEFT] = true;
			}
			if (e.button.button == SDL_BUTTON_RIGHT)
			{
				mousebutt[RIGHT] = true;
			}
			if (e.button.button == SDL_BUTTON_MIDDLE)
			{
				mousebutt[MIDDLE] = true;
			}
		}
		if (e.type == SDL_MOUSEBUTTONUP)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				mousebutt[LEFT] = false;
			}
			if (e.button.button == SDL_BUTTON_RIGHT)
			{
				mousebutt[RIGHT] = false;
			}
			if (e.button.button == SDL_BUTTON_MIDDLE)
			{
				mousebutt[MIDDLE] = false;
			}
		}
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				{
					gameinit::getG()->setrun(false);
					gameinit::getG()->quitSdl();
					break; 
				}
				case SDLK_SPACE:
				{
					keybutt[_SPACE_] = true;
					break;
				}
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_SPACE:
				{
					keybutt[_SPACE_] = false;
					break;
				}
			}
		}
	}
}
