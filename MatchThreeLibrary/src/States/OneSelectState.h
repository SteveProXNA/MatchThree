#ifndef _ONE_SELECT_STATE_H_
#define _ONE_SELECT_STATE_H_
//#pragma once

#include "BaseState.h"
#include "../Constants.h"

namespace MatchThree
{
    class OneSelectState : public BaseState
    {
    public:
        void Init();
        StateType Update(float delta);
    };
}

#endif//_ONE_SELECT_STATE_H_