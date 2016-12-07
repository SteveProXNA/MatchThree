#include "DropGemState.h"
#include "../Engine.h"

namespace MatchThree
{
	void DropGemState::Init()
	{
		// Get cell to replenish and add all cells above to be moved down.
		replenishCell = Engine::Instance().BoardManager().GetReplenishCell();
		Engine::Instance().BoardManager().MoveCellsDown(replenishCell);

		// Setup animation for all cells in this column.
		Engine::Instance().AnimateManager().Init();
		DirectionType direction = DOWN_DIRECTION;

		// Replenish current cell unconditionally.
		Engine::Instance().AnimateManager().SetupAnimation(replenishCell, -GEM_HEIGHT, 0, DOWN_DIRECTION);

		UCHAR cellAbove;
		UCHAR currentCell = replenishCell;
		if (currentCell >= MAX_ROWS)
		{
			while (true)
			{
				cellAbove = currentCell - MAX_ROWS;
				Engine::Instance().AnimateManager().SetupAnimation(cellAbove, -GEM_HEIGHT, 0, DOWN_DIRECTION);

				if (cellAbove < MAX_ROWS)
				{
					break;
				}

				currentCell = cellAbove;
			}
		}

		// Begin animation.
		Engine::Instance().AnimateManager().SetAnimationRunning(true);
	}

	StateType DropGemState::Update(float delta)
	{
		Engine::Instance().AnimateManager().Animate(delta);
		bool animationRunning = Engine::Instance().AnimateManager().GetAnimationRunning();

		if (animationRunning)
		{
			return DROP_GEMS_STATE;
		}

		// Gem dropped down: update score
		Engine::Instance().ScoreManager().Update();

		// Play audio if and only if gem below (or at bottom row).
		bool playAudio = false;
		UCHAR bottomRow = (MAX_ROWS - 1) * MAX_ROWS;

		if (replenishCell >= bottomRow)
		{
			playAudio = true;
		}
		else
		{
			UCHAR cellBelow = replenishCell + MAX_ROWS;
			char* board = Engine::Instance().BoardManager().GetBoard();

			char gem = board[cellBelow];
			if (EMPTY_GEM != gem)
			{
				playAudio = true;
			}
		}

		if (playAudio)
		{
			Engine::Instance().AudioManager().PlayAudio(MARBLE_AUDIO);
		}

		// Remove replenished cell from the set.
		Engine::Instance().BoardManager().RemoveEmptyCell();

		int count = Engine::Instance().BoardManager().CountMatches();
		if (count > 0)
		{
			return REPLENISH_STATE;
		}

		// Before resume game play, check new possible matches!
		Engine::Instance().BoardManager().Scan();

		count = Engine::Instance().BoardManager().CountMatches();
		if (count > 0)
		{
			Engine::Instance().BoardManager().EmptyGemCells();
			return REPLENISH_STATE;
		}

		// All cells replenished.
		return ONE_SELECT_STATE;
	}

}