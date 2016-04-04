#include "AnimateManager.h"
#include "../Engine.h"
#include <memory>

namespace MatchThree
{
    void AnimateManager::Init()
    {
        Reset();
    }

    void AnimateManager::Animate(float delta)
    {
        // No animation = quit.
        if (!animationRunning)
        {
            return;
        }

        // No objects to animate = quit.
        if (0 == animateObjects.size())
        {
            return;
        }

        // Animate all objects here.
        std::vector<UCHAR>::iterator iterator;
        for (iterator = animateObjects.begin(); iterator != animateObjects.end(); ++iterator)
        {
            UCHAR index = *iterator;
            const float step = delta / 1000 * animateDelay;

            if (LEFT_DIRECTION == direction[index])         { displaceX[index] -= step; }
            else if (RIGHT_DIRECTION == direction[index])   { displaceX[index] += step; }
            else if (UP_DIRECTION == direction[index])      { displaceY[index] -= step; }
            else if (DOWN_DIRECTION == direction[index])    { displaceY[index] += step; }
        }

        // Uniform animate.
        for (iterator = animateObjects.begin(); iterator != animateObjects.end(); ++iterator)
        {
            UCHAR index = *iterator;

            if (LEFT_DIRECTION == direction[index] && displaceX[index] <= stopDist[index])      { animationRunning = false; }
            else if (RIGHT_DIRECTION == direction[index] && displaceX[index] >= stopDist[index]){ animationRunning = false; }
            else if (UP_DIRECTION == direction[index] && displaceY[index] <= stopDist[index])   { animationRunning = false; }
            else if (DOWN_DIRECTION == direction[index] && displaceY[index] >= stopDist[index]) { animationRunning = false; }
        }

        if (!animationRunning)
        {
            Reset();
        }
    }

    void AnimateManager::Reset()
    {
        animateObjects.clear();

        memset(stopDist, 0, sizeof(stopDist));
        memset(displaceX, 0, sizeof(displaceX));
        memset(displaceY, 0, sizeof(displaceY));
        memset(direction, 0, sizeof(direction));
    }

    void AnimateManager::SetupAnimation(short index, short start, short stop, DirectionType way)
    {
        UCHAR object = static_cast<UCHAR>(index);
        animateObjects.push_back(object);

        stopDist[index] = stop;
        direction[index] = way;

        if (LEFT_DIRECTION == direction[index])         { displaceX[index] = start; }
        else if (RIGHT_DIRECTION == direction[index])   { displaceX[index] = start; }
        else if (UP_DIRECTION == direction[index])      { displaceY[index] = start; }
        else if (DOWN_DIRECTION == direction[index])    { displaceY[index] = start; }
    }

}