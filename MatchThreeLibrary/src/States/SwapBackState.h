#ifndef _SWAP_BACK_STATE_H_
#define _SWAP_BACK_STATE_H_
//#pragma once

#include "BaseState.h"
#include "../Constants.h"

namespace MatchThree
{
    class SwapBackState : public BaseState
    {
    public:
        void Init();
        StateType Update(float delta);

    protected:
        UCHAR oneSelect;
        UCHAR twoSelect;
    };
}

#endif//_SWAP_BACK_STATE_H_