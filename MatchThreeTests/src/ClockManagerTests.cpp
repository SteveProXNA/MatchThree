#include "gtest/gtest.h"
#include "Manager/ClockManager.h"

using namespace testing;
using namespace MatchThree;

class ClockManagerTests : public ::testing::Test
{
protected:
    void SetUp()
    {
        clockManager.Init();
    }

    ClockManager clockManager;
};

TEST_F(ClockManagerTests, Update)
{
    clockManager.Update(16.67f);
}