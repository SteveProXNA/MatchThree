#ifndef _BOARD_MANAGER_H_
#define _BOARD_MANAGER_H_

#include "../Constants.h"
#include <set>

using namespace std;

namespace MatchThree
{
	class BoardManager
	{
	public:
		BoardManager() : oneSelect(NO_SELECTION), twoSelect(NO_SELECTION) {}
		~BoardManager() {}

		void Init();
		void Init(const char* filename);
		void Render();
		void Scan();
		UCHAR Transpose(UCHAR index);

		char* GetBoard() { return board; }
		char GetGemCell(UCHAR index) const { return board[index]; }
		void SetGemCell(UCHAR index);
		void SwapGemCells(UCHAR oneSelect, UCHAR twoSelect);
		void EmptyGemCells();
		void MoveCellsDown(UCHAR replenishCell);
		void RemoveEmptyCell();

		set<UCHAR> GetTranspd() { return transpd; }
		int CountMatches() const { return matches.size(); }

		UCHAR GetReplenishCell() const { return replenishCell; }
		void SetReplenishCell(UCHAR replenishCell) { this->replenishCell = replenishCell; }
		UCHAR GetOneSelect() const { return oneSelect; }
		UCHAR GetTwoSelect() const { return twoSelect; }
		void SetOneSelect(UCHAR index) { oneSelect = index; }
		void SetTwoSelect(UCHAR index) { twoSelect = index; }

	private:
		char board[MAX_ROWS  * MAX_COLS];
		set<UCHAR>::iterator iterator;
		set<UCHAR> matches;
		set<UCHAR> transpd;

		UCHAR replenishCell;
		UCHAR oneSelect;
		UCHAR twoSelect;
	};
}

#endif//_BOARD_MANAGER_H_