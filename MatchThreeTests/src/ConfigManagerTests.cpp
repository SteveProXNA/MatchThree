#include "gtest/gtest.h"
#include "Manager/ConfigManager.h"
#include "Constants.h"

using namespace testing;
using namespace MatchThree;

class ConfigManagerTests : public ::testing::Test
{
public:
    ConfigManagerTests()    {}
    ~ConfigManagerTests()   {}
protected:
    ConfigManager configManager;
};

TEST_F(ConfigManagerTests, Init)
{
    configManager.Init();
    ASSERT_EQ(60, configManager.GetConfig(FPS_CONFIG));
    ASSERT_EQ(1, configManager.GetConfig(FULL_SCREEN_CONFIG));
    ASSERT_EQ(60, configManager.GetConfig(CLOCK_LENGTH_CONFIG));
    ASSERT_EQ(0, configManager.GetConfig(GAME_MODE_CONFIG));
    ASSERT_EQ(0, configManager.GetConfig(AUDIO_SET_CONFIG));
    ASSERT_EQ(250, configManager.GetConfig(GEM_ANIMATE_DELAY));
}