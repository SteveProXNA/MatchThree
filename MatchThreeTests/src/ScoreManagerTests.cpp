#include "gtest/gtest.h"
#include "Manager/ScoreManager.h"

using namespace testing;
using namespace MatchThree;

class ScoreManagerTests : public ::testing::Test
{
protected:
	void SetUp()
	{
		scoreManager.Init();
	}

	ScoreManager scoreManager;
};

TEST_F(ScoreManagerTests, Update)
{
	scoreManager.Update();
}