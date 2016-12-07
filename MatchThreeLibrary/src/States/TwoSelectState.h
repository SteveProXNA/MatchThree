#ifndef _TWO_SELECT_STATE_H_
#define _TWO_SELECT_STATE_H_

#include "BaseState.h"
#include "../Constants.h"

namespace MatchThree
{
	class TwoSelectState : public BaseState
	{
	public:
		void Init();
		StateType Update(float delta);
	};
}

#endif//_TWO_SELECT_STATE_H_