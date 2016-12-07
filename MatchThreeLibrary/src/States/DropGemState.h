#ifndef _DROP_GEM_STATE_H_
#define _DROP_GEM_STATE_H_

#include "BaseState.h"
#include "../Constants.h"

namespace MatchThree
{
	class DropGemState : public BaseState
	{
	public:
		void Init();
		StateType Update(float delta);

	private:
		UCHAR replenishCell;
	};
}

#endif//_DROP_GEM_STATE_H_