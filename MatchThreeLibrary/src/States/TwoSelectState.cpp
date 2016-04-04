#pragma once

#include "TwoSelectState.h"
#include "../Engine.h"

namespace MatchThree
{
    void TwoSelectState::Init()
    {
        Engine::Instance().BoardManager().SetTwoSelect(NO_SELECTION);
    }

    StateType TwoSelectState::Update(float delta)
    {
        bool leftMouse = Engine::Instance().InputManager().IsMouseButton(LEFT_BUTTON_DOWN);
        if (!leftMouse)
        {
            return TWO_SELECT_STATE;
        }

        UCHAR index = 0;
        bool hit = Engine::Instance().InputManager().GetGemCell(index);

        if (!hit)
        {
            return TWO_SELECT_STATE;
        }

        Engine::Instance().BoardManager().SetTwoSelect(index);
        UCHAR oneSelect = Engine::Instance().BoardManager().GetOneSelect();
        UCHAR twoSelect = Engine::Instance().BoardManager().GetTwoSelect();

        // Select same cell twice: reset.
        if (oneSelect == twoSelect)
        {
            Engine::Instance().BoardManager().SetGemCell(index);
            return ONE_SELECT_STATE;
        }

        // Validate two gems are adjacent before swapping!
        UCHAR diff = abs(oneSelect - twoSelect);
        if (!(1 == diff || MAX_ROWS == diff))
        {
            Engine::Instance().AudioManager().PlayAudio(BUZZ_AUDIO);
            return TWO_SELECT_STATE;
        }

        Engine::Instance().AudioManager().PlayAudio(CLICK_AUDIO);
        Engine::Instance().BoardManager().SetTwoSelect(index);
        Engine::Instance().BoardManager().SetGemCell(index);

        return SWAP_FORWARD_STATE;
    }

}