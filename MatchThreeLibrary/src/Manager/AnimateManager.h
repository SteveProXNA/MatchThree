#ifndef _ANIMATE_MANAGER_H_
#define _ANIMATE_MANAGER_H_
//#pragma once

#include <vector>
#include "../Constants.h"

using namespace std;

namespace MatchThree
{
    class AnimateManager
    {
    public:
        AnimateManager()    {}
        ~AnimateManager()   {}

        void Init();
        void Animate(float delta);
        void Reset();

        void SetupAnimation(short index, short start, short stop, DirectionType way);
        void SetAnimateDelay(short animateDelay) { this->animateDelay = animateDelay; }

        float GetDisplaceX(UCHAR index) const { return displaceX[index]; }
        float GetDisplaceY(UCHAR index) const { return displaceY[index]; }

        bool GetAnimationRunning() const { return animationRunning; }
        void SetAnimationRunning(bool animationRunning) { this->animationRunning = animationRunning; }

    private:
        std::vector<UCHAR> animateObjects;

        short stopDist[MAX_ROWS  * MAX_COLS];
        float displaceX[MAX_ROWS  * MAX_COLS];
        float displaceY[MAX_ROWS  * MAX_COLS];
        char direction[MAX_ROWS  * MAX_COLS];

        bool animationRunning;
        short animateDelay;
    };
}

#endif//_ANIMATE_MANAGER_H_