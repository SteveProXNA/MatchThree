#include "TitleScreen.h"
#include "../Engine.h"

namespace MatchThree
{
	void TitleScreen::Init()
	{
		timer = 0.0f;
		title = true;
	}

	ScreenType TitleScreen::Update(float delta)
	{
		Engine::Instance().InputManager().Update();

		bool leftMouse = Engine::Instance().InputManager().IsMouseButton(LEFT_BUTTON_DOWN);
		if (leftMouse)
		{
			return PLAY_SCREEN;
		}

		timer += delta;
		if (timer >= TITLE_DELAY)
		{
			timer = 0.0f;
			title = !title;
		}

		return TITLE_SCREEN;
	}

	void TitleScreen::Render()
	{
		Engine::Instance().ContentManager().RenderBackgroundImage();
		Engine::Instance().ContentManager().RenderSteveSmallImage();
		Engine::Instance().ContentManager().RenderTitleTextImage(title);
	}

}