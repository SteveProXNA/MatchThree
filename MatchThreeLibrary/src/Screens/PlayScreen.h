#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

#include "BaseScreen.h"
#include "../Constants.h"
#include "../States/BaseState.h"

namespace MatchThree
{
	class PlayScreen : public BaseScreen
	{
	public:
		void Init();
		ScreenType Update(float delta);
		void Render();
		void SetStates(
			BaseState* oneSelectState,
			BaseState* twoSelectState,
			BaseState* swapForwardState,
			BaseState* swapBackState,
			BaseState* replenishState,
			BaseState* dropGemState);

	private:
		BaseState* states[MAX_STATES];
		StateType currState;
		StateType nextState;
	};
}

#endif//_PLAY_SCREEN_H_