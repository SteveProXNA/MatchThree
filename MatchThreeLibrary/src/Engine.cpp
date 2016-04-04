#include "Engine.h"
#include <ctime>

namespace MatchThree
{
    void Engine::Init()
    {
        srand(static_cast<int>(std::time(0)));

        logManager.Init();
        configManager.Init();
        contentManager.Init();
        inputManager.Init();

        short animateDelay = configManager.GetConfig(GEM_ANIMATE_DELAY);
        animateManager.SetAnimateDelay(animateDelay);

        m_bFullScreen = (1 == configManager.GetConfig(FULL_SCREEN_CONFIG));
        SetScreen();

        bool audioSet = (1 == configManager.GetConfig(AUDIO_SET_CONFIG));
        audioManager.Init(audioSet);

        // Finally initialize screen.
        screenManager.Init();

        SDL_WM_SetCaption("", NULL);
        SDL_Init(SDL_INIT_EVERYTHING);
    }

    void Engine::Play()
    {
        static float fTickTrigger = 0.0f;
        float fTickCount;

        int fps = configManager.GetConfig(FPS_CONFIG);
        
        float delta = 1000.0f / fps;

        bool running = true;
        while (running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                // Users can press ESC any time to quit game!
                switch (event.type)
                {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    {
                        SDLKey key = event.key.keysym.sym;
                        if (SDLK_ESCAPE == key)
                        {
                            running = false;
                        }
                        if (SDLK_RETURN == key)
                        {
                            m_bFullScreen = !m_bFullScreen;
                            SetScreen();
                        }
                    }
                    break;
                }
            }

            fTickCount = static_cast<float>(SDL_GetTicks());
            if (fTickCount >= fTickTrigger)
            {
                fTickTrigger = fTickCount + delta;

                screenManager.Update(delta);
                screenManager.Render();

                SDL_Flip(screen);
            }
        }
    }

    void Engine::Quit()
    {
        screenManager.Quit();
        contentManager.Quit();
        logManager.Quit();

        SDL_Quit();
    }

    void Engine::SetScreen()
    {
        Uint32 flags = m_bFullScreen ? SDL_FULLSCREEN : SDL_SWSURFACE;
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, flags);
    }

}