#include "ScreenManager.h"
#include "../Constants.h"
#include "../Engine.h"

namespace MatchThree
{
    void ScreenManager::Init()
    {
        InsertScreens();
        InsertStates();

        // Pass games states to play screen.
        screens[PLAY_SCREEN]->SetStates(oneSelectState, twoSelectState, swapForwardState, swapBackState, replenishState, dropGemState);

        currScreen = nextScreen = SPLASH_SCREEN;
        screens[currScreen]->Init();
    }

    void ScreenManager::Update(float delta)
    {
        if (currScreen != nextScreen)
        {
            currScreen = nextScreen;
            screens[currScreen]->Init();
        }

        nextScreen = screens[currScreen]->Update(delta);
    }

    void ScreenManager::Render()
    {
        screens[currScreen]->Render();
    }

    void ScreenManager::Quit()
    {
        DeleteScreens();
        DeleteStates();
    }

    void ScreenManager::InsertScreens()
    {
        splashScreen = new SplashScreen();
        titleScreen = new TitleScreen();
        playScreen = new PlayScreen();
        overScreen = new OverScreen();

        screens[SPLASH_SCREEN] = splashScreen;
        screens[TITLE_SCREEN] = titleScreen;
        screens[PLAY_SCREEN] = playScreen;
        screens[OVER_SCREEN] = overScreen;
    }
    void ScreenManager::InsertStates()
    {
        oneSelectState = new OneSelectState();
        twoSelectState = new TwoSelectState();
        swapForwardState = new SwapForwardState();
        swapBackState = new SwapBackState();
        replenishState = new ReplenishState();
        dropGemState = new DropGemState();
    }
    void ScreenManager::DeleteScreens()
    {
        for (char index = 0; index < MAX_SCREENS; ++index)
        {
            BaseScreen* screen = screens[index];
            if (NULL != screen)
            {
                delete screen;
                screen = NULL;
            }
        }
    }
    void DeleteState(BaseState* state)
    {
        if (NULL != state)
        {
            delete state;
            state = NULL;
        }
    }
    void ScreenManager::DeleteStates()
    {
        DeleteState(oneSelectState);
        DeleteState(twoSelectState);
        DeleteState(swapForwardState);
        DeleteState(swapBackState);
        DeleteState(replenishState);
        DeleteState(dropGemState);
    }

}