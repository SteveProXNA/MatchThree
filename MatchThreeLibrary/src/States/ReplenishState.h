#ifndef _REPLENISH_STATE_H_
#define _REPLENISH_STATE_H_
//#pragma once

#include "BaseState.h"
#include "../Constants.h"
#include <set>

using namespace std;

namespace MatchThree
{
    class ReplenishState : public BaseState
    {
    public:
        void Init() {}
        StateType Update(float delta);
    };
}

#endif//_REPLENISH_STATE_H_