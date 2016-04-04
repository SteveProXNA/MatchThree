#pragma once

#include "ReplenishState.h"
#include "../Engine.h"

namespace MatchThree
{
    StateType ReplenishState::Update(float delta)
    {
        set<UCHAR> transpd = Engine::Instance().BoardManager().GetTranspd();

        set<UCHAR>::iterator iterator = transpd.begin();
        UCHAR index = *iterator;

        UCHAR replenishCell = Engine::Instance().BoardManager().Transpose(index);
        Engine::Instance().BoardManager().SetReplenishCell(replenishCell);

        return DROP_GEMS_STATE;
    }

}