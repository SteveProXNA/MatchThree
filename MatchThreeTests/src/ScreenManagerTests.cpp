#include "gtest/gtest.h"
#include "Manager/ScreenManager.h"

using namespace testing;
using namespace MatchThree;

class ScreenManagerTests : public ::testing::Test
{
protected:
	ScreenManager screenManager;
};

TEST_F(ScreenManagerTests, Update)
{
    screenManager.Init();
    screenManager.Quit();
}