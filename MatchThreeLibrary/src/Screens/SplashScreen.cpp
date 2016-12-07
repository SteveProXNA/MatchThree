#include "SplashScreen.h"
#include "../Engine.h"

namespace MatchThree
{
	void SplashScreen::Init()
	{
		timer = 0.0f;
	}

	ScreenType SplashScreen::Update(float delta)
	{
		Engine::Instance().InputManager().Update();

		bool leftMouse = Engine::Instance().InputManager().IsMouseButton(LEFT_BUTTON_DOWN);
		if (leftMouse)
		{
			return TITLE_SCREEN;
		}

		timer += delta;
		if (timer >= SPLASH_DELAY)
		{
			return TITLE_SCREEN;
		}

		return SPLASH_SCREEN;
	}

	void SplashScreen::Render()
	{
		Engine::Instance().ContentManager().RenderSteveProImage();
	}

}