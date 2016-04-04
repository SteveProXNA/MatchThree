#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_
//#pragma once

#include "BaseScreen.h"
#include "../Constants.h"

namespace MatchThree
{
    class TitleScreen : public BaseScreen
    {
    public:
        void Init();
        ScreenType Update(float delta);
        void Render();

    private:
        float timer;
        bool title;
    };
}

#endif//_TITLE_SCREEN_H_