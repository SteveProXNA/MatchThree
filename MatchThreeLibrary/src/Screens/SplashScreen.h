#ifndef _SPLASH_SCREEN_H_
#define _SPLASH_SCREEN_H_
//#pragma once

#include "BaseScreen.h"
#include "../Constants.h"

namespace MatchThree
{
    class SplashScreen : public BaseScreen
    {
    public:
        void Init();
        ScreenType Update(float delta);
        void Render();

    private:
        float timer;
    };
}

#endif//_SPLASH_SCREEN_H_