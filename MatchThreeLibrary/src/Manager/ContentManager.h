#ifndef _CONTENT_MANAGER_H_
#define _CONTENT_MANAGER_H_
//#pragma once

#include <SDL/SDL.h>
#include "../Constants.h"

namespace MatchThree
{
    class ContentManager
    {
    public:
        void Init();
        void Quit();

        void RenderSteveProImage();
        void RenderSteveSmallImage();
        void RenderBackgroundImage();
        void RenderTitleTextImage(bool title);
        void RenderGameOverImage();

        SDL_Surface* const GetGemImage(char gemType) { return gemImage[gemType]; }
        SDL_Surface* const GetScoreImage(char number) { return scoreImage[number]; }
        SDL_Surface* const GetTimerImage(char number) { return timerImage[number]; }

    private:
        SDL_Surface* steveproImage;
        SDL_Surface* steveSmallImage;
        SDL_Surface* backgroundImage;
        SDL_Surface* titleTextImage;
        SDL_Surface* titleTextImageBlink;
        SDL_Surface* gameOverImage;

        SDL_Surface* gemImage[MAX_GEMS * 2 + 1];
        SDL_Surface* scoreImage[SCORE_IMAGES];
        SDL_Surface* timerImage[TIMER_IMAGES];
    };
}

#endif//_CONTENT_MANAGER_H_