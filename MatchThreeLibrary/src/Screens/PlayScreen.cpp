#pragma once

#include "PlayScreen.h"
#include "../Engine.h"

namespace MatchThree
{
    void PlayScreen::SetStates(
        BaseState* oneSelectState,
        BaseState* twoSelectState,
        BaseState* swapForwardState,
        BaseState* swapBackState,
        BaseState* replenishState,
        BaseState* dropGemState)
    {
        states[ONE_SELECT_STATE] = oneSelectState;
        states[TWO_SELECT_STATE] = twoSelectState;
        states[SWAP_FORWARD_STATE] = swapForwardState;
        states[SWAP_BACK_STATE] = swapBackState;
        states[REPLENISH_STATE] = replenishState;
        states[DROP_GEMS_STATE] = dropGemState;
    }

    void PlayScreen::Init()
    {
        Engine::Instance().AudioManager().PlayAudio(GO_AUDIO);

        Engine::Instance().AnimateManager().Init();
        Engine::Instance().BoardManager().Init();
        Engine::Instance().ClockManager().Init();
        Engine::Instance().ScoreManager().Init();

        int gameMode = Engine::Instance().ConfigManager().GetConfig(GAME_MODE_CONFIG);
        gameType = static_cast<GameType>(gameMode);

        // Before game start, check random matches!
        Engine::Instance().BoardManager().Scan();

        int count = Engine::Instance().BoardManager().CountMatches();
        if (count > 0)
        {
            Engine::Instance().BoardManager().EmptyGemCells();
            currState = nextState = REPLENISH_STATE;
        }
        else
        {
            currState = nextState = ONE_SELECT_STATE;
        }

        states[currState]->Init();
    }

    ScreenType PlayScreen::Update(float delta)
    {
        // Quit game anytime by right mouse click!
        Engine::Instance().InputManager().Update();

        bool rightMouse = Engine::Instance().InputManager().IsMouseButton(RIGHT_BUTTON_DOWN);
        if (rightMouse)
        {
            return OVER_SCREEN;
        }

        // If timed game then check clock = 0; Game Over.
        if (TIMED_GAME == gameType)
        {
            Engine::Instance().ClockManager().Update(delta);

            bool isGameOver = Engine::Instance().ClockManager().IsGameOver();
            if (isGameOver)
            {
                return OVER_SCREEN;
            }
        }

        // Delegate work to individual game state.
        if (currState != nextState)
        {
            currState = nextState;
            states[currState]->Init();
        }

        nextState = states[currState]->Update(delta);
        return PLAY_SCREEN;
    }

    void PlayScreen::Render()
    {
        Engine::Instance().ContentManager().RenderBackgroundImage();
        Engine::Instance().ContentManager().RenderSteveSmallImage();
        Engine::Instance().BoardManager().Render();
        Engine::Instance().ScoreManager().Render();

        // Future: different game modes!
        if (TIMED_GAME == gameType)
        {
            Engine::Instance().ClockManager().Render();
        }
    }

}