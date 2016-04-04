#pragma once

#include "OverScreen.h"
#include "../Engine.h"

namespace MatchThree
{
    void OverScreen::Init()
    {
        int gameMode = Engine::Instance().ConfigManager().GetConfig(GAME_MODE_CONFIG);
        gameType = static_cast<GameType>(gameMode);

        Engine::Instance().AudioManager().PlayAudio(OVER_AUDIO);
    }

    ScreenType OverScreen::Update(float delta)
    {
        Engine::Instance().InputManager().Update();
        bool leftMouse = Engine::Instance().InputManager().IsMouseButton(LEFT_BUTTON_DOWN);
        if (leftMouse)
        {
            return PLAY_SCREEN;
        }

        return OVER_SCREEN;
    }

    void OverScreen::Render()
    {
        Engine::Instance().ContentManager().RenderBackgroundImage();
        Engine::Instance().ContentManager().RenderSteveSmallImage();
        Engine::Instance().BoardManager().Render();
        Engine::Instance().ScoreManager().Render();
        Engine::Instance().ContentManager().RenderGameOverImage();

        // Future: different game modes!
        if (TIMED_GAME == gameType)
        {
            Engine::Instance().ClockManager().Render();
        }
    }

}