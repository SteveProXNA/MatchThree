#include "SwapForwardState.h"
#include "../Engine.h"

namespace MatchThree
{
	void SwapForwardState::Init()
	{
		oneSelect = Engine::Instance().BoardManager().GetOneSelect();
		twoSelect = Engine::Instance().BoardManager().GetTwoSelect();

		short oneStop, twoStop;
		DirectionType oneWay, twoWay;

		// Determine direction and stopping.
		short diff = oneSelect - twoSelect;
		if (-1 == diff)
		{
			oneStop = GEM_WIDTH; twoStop = -oneStop;
			oneWay = RIGHT_DIRECTION; twoWay = LEFT_DIRECTION;
		}
		else if (1 == diff)
		{
			oneStop = -GEM_WIDTH; twoStop = -oneStop;
			oneWay = LEFT_DIRECTION; twoWay = RIGHT_DIRECTION;
		}
		else if (-MAX_ROWS == diff)
		{
			oneStop = GEM_HEIGHT; twoStop = -oneStop;
			oneWay = DOWN_DIRECTION; twoWay = UP_DIRECTION;
		}
		else if (MAX_ROWS == diff)
		{
			oneStop = -GEM_HEIGHT; twoStop = -oneStop;
			oneWay = UP_DIRECTION; twoWay = DOWN_DIRECTION;
		}

		Engine::Instance().AnimateManager().Init();
		Engine::Instance().AnimateManager().SetupAnimation(oneSelect, 0, oneStop, oneWay);
		Engine::Instance().AnimateManager().SetupAnimation(twoSelect, 0, twoStop, twoWay);
		Engine::Instance().AnimateManager().SetAnimationRunning(true);
	}

	StateType SwapForwardState::Update(float delta)
	{
		Engine::Instance().AnimateManager().Animate(delta);
		bool animationRunning = Engine::Instance().AnimateManager().GetAnimationRunning();

		if (animationRunning)
		{
			return SWAP_FORWARD_STATE;
		}

		// Now, forward animation complete, temporarily swap;
		// If matches then replenish otherwise swap back state.
		UCHAR tmp = oneSelect;
		oneSelect = twoSelect;
		twoSelect = tmp;

		Engine::Instance().BoardManager().SetOneSelect(oneSelect);
		Engine::Instance().BoardManager().SetTwoSelect(twoSelect);

		Engine::Instance().BoardManager().SetGemCell(oneSelect);
		Engine::Instance().BoardManager().SetGemCell(twoSelect);
		Engine::Instance().BoardManager().SwapGemCells(oneSelect, twoSelect);

		// Scan board for matches!
		Engine::Instance().BoardManager().Scan();
		int count = Engine::Instance().BoardManager().CountMatches();

		if (count > 0)
		{
			Engine::Instance().BoardManager().EmptyGemCells();
			return REPLENISH_STATE;
		}

		// No matches so swap back.
		Engine::Instance().BoardManager().SetGemCell(oneSelect);
		Engine::Instance().BoardManager().SetGemCell(twoSelect);

		return SWAP_BACK_STATE;
	}

}