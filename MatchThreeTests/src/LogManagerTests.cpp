#include "gtest/gtest.h"
#include "Manager/LogManager.h"

using namespace testing;
using namespace MatchThree;

class LogManagerTests : public ::testing::Test
{
public:
	LogManagerTests()   {}
	~LogManagerTests()  {}
protected:
	LogManager logManager;
};

TEST_F(LogManagerTests, Write)
{
	logManager.Init();
	logManager.Write("logging test\n");
	logManager.Quit();
}