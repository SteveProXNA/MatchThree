#include "gtest/gtest.h"
#include "Manager/ContentManager.h"

using namespace testing;
using namespace MatchThree;

class ContentManagerTests : public ::testing::Test
{
protected:
	ContentManager contentManager;
};

TEST_F(ContentManagerTests, Load)
{
	contentManager.Init();
	contentManager.Quit();
}