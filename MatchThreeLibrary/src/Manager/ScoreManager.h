#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_
//#pragma once

#include "../Constants.h"

namespace MatchThree
{
    class ScoreManager
    {
    public:
        ScoreManager()  {}
        ~ScoreManager() {}

        void Init();
        void Update();
        void Render();

    private:
        short score;
    };
}

#endif//_SCORE_MANAGER_H_