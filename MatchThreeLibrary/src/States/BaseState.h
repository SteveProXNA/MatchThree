#ifndef _BASE_STATE_H_
#define _BASE_STATE_H_

#include "../Constants.h"

namespace MatchThree
{
	class BaseState
	{
	public:
		BaseState() {}
		virtual ~BaseState() {}

		virtual void Init() {}
		virtual StateType Update(float delta) = 0;
	};
}

#endif//_BASE_STATE_H_