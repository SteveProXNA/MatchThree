#pragma once

#include "SwapBackState.h"
#include "../Engine.h"

namespace MatchThree
{
    void SwapBackState::Init()
    {
        oneSelect = Engine::Instance().BoardManager().GetOneSelect();
        twoSelect = Engine::Instance().BoardManager().GetTwoSelect();

        short oneStop, twoStop;
        DirectionType oneWay, twoWay;

        // Determine direction and stopping.
        short diff = oneSelect - twoSelect;
        if (-1 == diff)
        {
            oneStop = GEM_WIDTH; twoStop = -oneStop;
            oneWay = RIGHT_DIRECTION; twoWay = LEFT_DIRECTION;
        }
        else if (1 == diff)
        {
            oneStop = -GEM_WIDTH; twoStop = -oneStop;
            oneWay = LEFT_DIRECTION; twoWay = RIGHT_DIRECTION;
        }
        else if (-MAX_ROWS == diff)
        {
            oneStop = GEM_HEIGHT; twoStop = -oneStop;
            oneWay = DOWN_DIRECTION; twoWay = UP_DIRECTION;
        }
        else if (MAX_ROWS == diff)
        {
            oneStop = -GEM_HEIGHT; twoStop = -oneStop;
            oneWay = UP_DIRECTION; twoWay = DOWN_DIRECTION;
        }

        Engine::Instance().AnimateManager().Init();
        Engine::Instance().AnimateManager().SetupAnimation(oneSelect, 0, oneStop, oneWay);
        Engine::Instance().AnimateManager().SetupAnimation(twoSelect, 0, twoStop, twoWay);
        Engine::Instance().AnimateManager().SetAnimationRunning(true);
    }

    StateType SwapBackState::Update(float delta)
    {
        Engine::Instance().AnimateManager().Animate(delta);
        bool animationRunning = Engine::Instance().AnimateManager().GetAnimationRunning();

        if (animationRunning)
        {
            return SWAP_BACK_STATE;
        }

        Engine::Instance().BoardManager().SetGemCell(oneSelect);
        Engine::Instance().BoardManager().SetGemCell(twoSelect);
        Engine::Instance().BoardManager().SwapGemCells(oneSelect, twoSelect);

        return ONE_SELECT_STATE;
    }

}