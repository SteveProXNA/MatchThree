#include "gtest/gtest.h"
#include "Engine.h"

using namespace MatchThree;

TEST(EngineTests, ConfigManagerConfig)
{
	Engine::Instance().ConfigManager().Init();
	Engine::Instance().ConfigManager().Init();

	int fps = Engine::Instance().ConfigManager().GetConfig(FPS_CONFIG);
	ASSERT_EQ(60, fps);
}

TEST(EngineTests, LogManagerWrite)
{
	Engine::Instance().LogManager().Init();
	Engine::Instance().LogManager().Write("engine test");
	Engine::Instance().LogManager().Quit();
}