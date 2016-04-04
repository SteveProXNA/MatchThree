#pragma once

#include "OneSelectState.h"
#include "../Engine.h"

namespace MatchThree
{
    void OneSelectState::Init()
    {
        Engine::Instance().BoardManager().SetOneSelect(NO_SELECTION);
    }

    StateType OneSelectState::Update(float delta)
    {
        bool leftMouse = Engine::Instance().InputManager().IsMouseButton(LEFT_BUTTON_DOWN);
        if (!leftMouse)
        {
            return ONE_SELECT_STATE;
        }

        UCHAR index = 0;
        bool hit = Engine::Instance().InputManager().GetGemCell(index);

        if (!hit)
        {
            return ONE_SELECT_STATE;
        }

        Engine::Instance().AudioManager().PlayAudio(CLICK_AUDIO);
        Engine::Instance().BoardManager().SetOneSelect(index);
        Engine::Instance().BoardManager().SetGemCell(index);

        return TWO_SELECT_STATE;
    }

}