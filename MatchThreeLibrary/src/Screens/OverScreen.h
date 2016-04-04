#ifndef _OVER_SCREEN_H_
#define _OVER_SCREEN_H_
//#pragma once

#include "BaseScreen.h"
#include "../Constants.h"

namespace MatchThree
{
    class OverScreen : public BaseScreen
    {
    public:
        void Init();
        ScreenType Update(float delta);
        void Render();
    };
}

#endif//_OVER_SCREEN_H_