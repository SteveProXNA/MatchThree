#ifndef _SWAP_FORWARD_STATE_H_
#define _SWAP_FORWARD_STATE_H_

#include "BaseState.h"
#include "../Constants.h"

namespace MatchThree
{
	class SwapForwardState : public BaseState
	{
	public:
		void Init();
		StateType Update(float delta);

	private:
		UCHAR oneSelect;
		UCHAR twoSelect;
	};
}

#endif//_SWAP_FORWARD_STATE_H_