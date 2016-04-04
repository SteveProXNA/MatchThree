#include "ContentManager.h"
#include "../Engine.h"
#include <string>

using namespace std;

namespace MatchThree
{
    void ContentManager::Init()
    {
        string root = "content/image/";

        steveproImage   = SDL_LoadBMP((root + "StevePro.bmp").c_str());
        steveSmallImage = SDL_LoadBMP((root + "SteveProSmall.bmp").c_str());
        backgroundImage = SDL_LoadBMP((root + "BackGround.bmp").c_str());
        titleTextImage  = SDL_LoadBMP((root + "TitleText.bmp").c_str());
        titleTextImageBlink = SDL_LoadBMP((root + "TitleTextBlink.bmp").c_str());
        gameOverImage   = SDL_LoadBMP((root + "GameOver.bmp").c_str());
        SDL_SetColorKey(gameOverImage, SDL_SRCCOLORKEY, SDL_MapRGB(gameOverImage->format, 255, 0, 255));

        // GEMS.
        string gems[MAX_GEMS * 2 + 1] =
        {
            "Empty.bmp", "Blue.bmp", "Green.bmp", "Purple.bmp", "Red.bmp", "Yellow.bmp",
            "BlueLarge.bmp", "GreenLarge.bmp", "PurpleLarge.bmp", "RedLarge.bmp", "YellowLarge.bmp"
        };
        gemImage[0] = NULL;
        for (char index = 1; index <= MAX_GEMS; ++index)
        {
            string gem = gems[index];
            string gemLarge = gems[index + MAX_GEMS];

            gemImage[index] = SDL_LoadBMP((root + gem).c_str());
            SDL_SetColorKey(gemImage[index], SDL_SRCCOLORKEY, SDL_MapRGB(gemImage[index]->format, 0, 0, 0));

            gemImage[index + MAX_GEMS] = SDL_LoadBMP((root + gemLarge).c_str());
            SDL_SetColorKey(gemImage[index + MAX_GEMS], SDL_SRCCOLORKEY, SDL_MapRGB(gemImage[index + MAX_GEMS]->format, 255, 255, 255));
        }

        // SCORES.
        root = "content/timer/";
        string scores[SCORE_IMAGES] =
        {
            "score_zero.bmp", "score_one.bmp", "score_two.bmp", "score_three.bmp", "score_four.bmp", "score_five.bmp",
            "score_six.bmp", "score_seven.bmp", "score_eight.bmp", "score_nine.bmp", "score_text.bmp"
        };
        for (int idx = 0; idx < SCORE_IMAGES; ++idx)
        {
            string score = scores[idx];
            scoreImage[idx] = SDL_LoadBMP((root + score).c_str());
        }

        // TIMER.
        root = "content/timer/";
        string timers[TIMER_IMAGES] =
        {
            "timer_zero.bmp", "timer_one.bmp", "timer_two.bmp", "timer_three.bmp", "timer_four.bmp", "timer_five.bmp",
            "timer_six.bmp", "timer_seven.bmp", "timer_eight.bmp", "timer_nine.bmp", "timer_seperator.bmp"
        };
        for (int idx = 0; idx < SCORE_IMAGES; ++idx)
        {
            string timer = timers[idx];
            timerImage[idx] = SDL_LoadBMP((root + timer).c_str());
        }
    }

    void ContentManager::Quit()
    {
        for (char index = 0; index < MAX_GEMS * 2 + 1; ++index)
        {
            SDL_FreeSurface(gemImage[index]);
        }
        for (char index = 0; index < SCORE_IMAGES; ++index)
        {
            SDL_FreeSurface(scoreImage[index]);
        }
        for (char index = 0; index < TIMER_IMAGES; ++index)
        {
            SDL_FreeSurface(timerImage[index]);
        }

        SDL_FreeSurface(steveproImage);
        SDL_FreeSurface(steveSmallImage);
        SDL_FreeSurface(backgroundImage);
        SDL_FreeSurface(titleTextImage);
        SDL_FreeSurface(titleTextImageBlink);
        SDL_FreeSurface(gameOverImage);
    }

    void ContentManager::RenderSteveProImage()
    {
        int x = (SCREEN_WIDTH - steveproImage->w) / 2;
        int y = (SCREEN_HEIGHT - steveproImage->h) / 2;

        SDL_Rect rect = { x, y, 0, 0 };
        SDL_BlitSurface(steveproImage, NULL, Engine::Instance().GetScreen(), &rect);
    }
    void ContentManager::RenderSteveSmallImage()
    {
        int x = (SCREEN_WIDTH - steveSmallImage->w);
        int y = (SCREEN_HEIGHT - steveSmallImage->h);

        SDL_Rect rect = { x, y, 0, 0 };
        SDL_BlitSurface(steveSmallImage, NULL, Engine::Instance().GetScreen(), &rect);
    }
    void ContentManager::RenderBackgroundImage()
    {
        SDL_BlitSurface(backgroundImage, NULL, Engine::Instance().GetScreen(), NULL);
    }
    void ContentManager::RenderTitleTextImage(bool title)
    {
        SDL_Rect rect = { TITLE_STARTX, TITLE_STARTY, 0, 0 };
        SDL_Surface* image = title ? titleTextImage : titleTextImageBlink;
        SDL_BlitSurface(image, NULL, Engine::Instance().GetScreen(), &rect);
    }
    void ContentManager::RenderGameOverImage()
    {
        SDL_Rect rect = { GAME_OVERX, GAME_OVERY, 0, 0 };
        SDL_BlitSurface(gameOverImage, NULL, Engine::Instance().GetScreen(), &rect);
    }

}