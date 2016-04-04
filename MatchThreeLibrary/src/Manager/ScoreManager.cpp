#include "ScoreManager.h"
#include "../Engine.h"

namespace MatchThree
{
    void ScoreManager::Init()
    {
        score = 0;
    }

    void ScoreManager::Update()
    {
        score++;

        // Safe guard: good luck if you score >= 1000!
        if (score >= 1000)
        {
            score = 0;
        }
    }

    void ScoreManager::Render()
    {
        SDL_Rect myRect = { SCORE_POSX, SCORE_POSY, 0, 0 };
        SDL_Surface* screen = Engine::Instance().GetScreen();

        char huns = score / 100;
        char bals = score % 100;

        char tens = bals / 10;
        char ones = bals % 10;

        SDL_Surface* image = Engine::Instance().ContentManager().GetScoreImage(ones);
        SDL_BlitSurface(image, NULL, screen, &myRect);

        if (tens > 0 || score > 99)
        {
            myRect.x = SCORE_POSX - image->w;

            image = Engine::Instance().ContentManager().GetScoreImage(tens);
            SDL_BlitSurface(image, NULL, screen, &myRect);
        }
        if (huns > 0)
        {
            myRect.x = SCORE_POSX - (2 * image->w);

            image = Engine::Instance().ContentManager().GetScoreImage(huns);
            SDL_BlitSurface(image, NULL, screen, &myRect);
        }

        myRect.x = SCORE_POSX - (4 * image->w);
        myRect.y = SCORE_POSY - image->h;

        image = Engine::Instance().ContentManager().GetScoreImage(10);
        SDL_BlitSurface(image, NULL, screen, &myRect);
    }

}