#ifndef _SCREEN_MANAGER_H_
#define _SCREEN_MANAGER_H_

#include "../Constants.h"
#include "../Screens/BaseScreen.h"
#include "../Screens/SplashScreen.h"
#include "../Screens/TitleScreen.h"
#include "../Screens/PlayScreen.h"
#include "../Screens/OverScreen.h"
#include "../States/BaseState.h"
#include "../States/OneSelectState.h"
#include "../States/TwoSelectState.h"
#include "../States/SwapForwardState.h"
#include "../States/SwapBackState.h"
#include "../States/ReplenishState.h"
#include "../States/DropGemState.h"

namespace MatchThree
{
	class ScreenManager
	{
	public:
		ScreenManager()     {}
		~ScreenManager()    {}

		void Init();
		void Quit();

		void Update(float delta);
		void Render();

	private:
		void InsertScreens();
		void DeleteScreens();
		void InsertStates();
		void DeleteStates();

		BaseScreen*     screens[MAX_SCREENS];
		SplashScreen*   splashScreen;
		TitleScreen*    titleScreen;
		PlayScreen*     playScreen;
		OverScreen*     overScreen;

		ScreenType currScreen;
		ScreenType nextScreen;

		OneSelectState*     oneSelectState;
		TwoSelectState*     twoSelectState;
		SwapForwardState*   swapForwardState;
		SwapBackState*      swapBackState;
		ReplenishState*     replenishState;
		DropGemState*       dropGemState;
	};
}

#endif//_SCREEN_MANAGER_H_