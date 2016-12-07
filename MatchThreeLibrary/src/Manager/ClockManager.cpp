#include "ClockManager.h"
#include "../Engine.h"

namespace MatchThree
{
	const short second = 1000;
	const short separator = 17;         // 17px for separator icon.

	void ClockManager::Init()
	{
		clock = Engine::Instance().ConfigManager().GetConfig(CLOCK_LENGTH_CONFIG);
		timer = 0;
	}

	void ClockManager::Update(float delta)
	{
		// Important: method will run only during game play!
		timer += delta;
		if (timer >= second)
		{
			timer = 0;
			if (clock > 0)
			{
				clock--;
				if (clock <= 0)
				{
					clock = 0;
				}
			}
		}
	}

	void ClockManager::Render()
	{
		SDL_Rect myRect = { CLOCK_POSX, CLOCK_POSY, 0, 0 };
		SDL_Surface* screen = Engine::Instance().GetScreen();

		char mins = clock / 60;
		char secs = clock % 60;

		char tens = secs / 10;
		char ones = secs % 10;

		SDL_Surface* image = Engine::Instance().ContentManager().GetTimerImage(ones);
		SDL_BlitSurface(image, NULL, screen, &myRect);

		Sint16 width = image->w;
		myRect.x = CLOCK_POSX - width;
		image = Engine::Instance().ContentManager().GetTimerImage(tens);
		SDL_BlitSurface(image, NULL, screen, &myRect);

		myRect.x = CLOCK_POSX - width - separator;
		image = Engine::Instance().ContentManager().GetTimerImage(10);
		SDL_BlitSurface(image, NULL, screen, &myRect);

		myRect.x = CLOCK_POSX - (2 * width) - separator;
		image = Engine::Instance().ContentManager().GetTimerImage(mins);
		SDL_BlitSurface(image, NULL, screen, &myRect);
	}

}