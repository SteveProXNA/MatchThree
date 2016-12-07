#include "gtest/gtest.h"
#include "Manager/AnimateManager.h"

using namespace testing;
using namespace MatchThree;

class AnimateManagerTests : public ::testing::Test
{
public:
	AnimateManager animateManager;
};

TEST_F(AnimateManagerTests, Init)
{
	animateManager.Init();
	animateManager.Animate(16.67f);
}