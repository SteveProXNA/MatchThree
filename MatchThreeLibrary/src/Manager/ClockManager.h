#ifndef _CLOCK_MANAGER_H_
#define _CLOCK_MANAGER_H_

#include "../Constants.h"

namespace MatchThree
{
	class ClockManager
	{
	public:
		ClockManager()  {}
		~ClockManager() {}

		void Init();
		void Update(float delta);
		void Render();
		bool IsGameOver() { return clock == 0; }

	private:
		short clock;
		float timer;
	};
}

#endif//_CLOCK_MANAGER_H_