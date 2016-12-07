#include "gtest/gtest.h"
#include "Manager/BoardManager.h"

using namespace testing;
using namespace MatchThree;

class BoardManagerTests : public ::testing::Test
{
protected:
	BoardManager boardManager;
};

TEST_F(BoardManagerTests, Init)
{
	boardManager.Init("board/board_init.txt");
	char* board = boardManager.GetBoard();
}

TEST_F(BoardManagerTests, Scan)
{
	boardManager.Init("board/board_scan.txt");
	boardManager.Scan();
	int matches = boardManager.CountMatches();
	ASSERT_EQ(3, matches);
}

TEST_F(BoardManagerTests, Transpose)
{
	UCHAR replenishCell = boardManager.Transpose(17);
	ASSERT_EQ(10, replenishCell);
}