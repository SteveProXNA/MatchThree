#ifndef _BASE_SCREEN_H_
#define _BASE_SCREEN_H_
//#pragma once

#include "../Constants.h"
#include "../States/BaseState.h"

namespace MatchThree
{
    class BaseScreen
    {
    public:
        BaseScreen() {}
        virtual ~BaseScreen() {}

        virtual void Init() = 0;
        virtual ScreenType Update(float delta) = 0;
        virtual void Render() = 0;

        // Slight code smell here: running out time to change...
        virtual void SetStates(
            BaseState* oneSelectState,
            BaseState* twoSelectState,
            BaseState* swapForwardState,
            BaseState* swapBackState,
            BaseState* replenishState,
            BaseState* dropGemState)
        {}

    protected:
        BaseState* states[MAX_STATES];
        GameType gameType;
        int xMouse;
        int yMouse;
    };
}

#endif//_BASE_SCREEN_H_