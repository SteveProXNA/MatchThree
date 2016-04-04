#include "gtest/gtest.h"
#include "Manager/AudioManager.h"

using namespace testing;
using namespace MatchThree;

class AudioManagerTests : public ::testing::Test
{
protected:
    void SetUp()
    {
        audioManager.Init(false);
    }

    AudioManager audioManager;
};

TEST_F(AudioManagerTests, Buzz)
{
    audioManager.PlayAudio(BUZZ_AUDIO);
}