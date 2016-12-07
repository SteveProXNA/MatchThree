#include "gtest/gtest.h"
#include "Manager/InputManager.h"
#include "Constants.h"

using namespace testing;
using namespace MatchThree;

class InputManagerTests : public ::testing::Test
{
public:
	InputManagerTests() : index(0) {}

protected:
	InputManager inputManager;
	UCHAR index;
	int xMouse;
	int yMouse;
};

TEST_F(InputManagerTests, Update)
{
	inputManager.Update();
	bool mouseButton = inputManager.IsMouseButton(NO_BUTTON_DOWN);
	ASSERT_TRUE(mouseButton);
}

TEST_F(InputManagerTests, Select)
{
	xMouse = GEM_STARTX + 45;
	yMouse = GEM_STARTY + 45;
	bool select = inputManager.GetGemCellCoords(xMouse, yMouse, index);
	ASSERT_EQ(9, (short)index);
}

TEST_F(InputManagerTests, Select0)
{
	xMouse = GEM_STARTX;
	yMouse = GEM_STARTY;
	bool select = inputManager.GetGemCellCoords(xMouse, yMouse, index);
	ASSERT_TRUE(select);
}
TEST_F(InputManagerTests, Select1)
{
	xMouse = GEM_STARTX - 1;
	yMouse = GEM_STARTY;
	bool select = inputManager.GetGemCellCoords(xMouse, yMouse, index);
	ASSERT_FALSE(select);
}
TEST_F(InputManagerTests, Select2)
{
	xMouse = GEM_STARTX;
	yMouse = GEM_STARTY - 1;
	bool select = inputManager.GetGemCellCoords(xMouse, yMouse, index);
	ASSERT_FALSE(select);
}
TEST_F(InputManagerTests, Select3)
{
	xMouse = SCREEN_WIDTH - 1;
	yMouse = GEM_STARTY;
	bool select = inputManager.GetGemCellCoords(xMouse, yMouse, index);
	ASSERT_FALSE(select);
}
TEST_F(InputManagerTests, Select4)
{
	xMouse = GEM_STARTX;
	yMouse = SCREEN_HEIGHT;
	bool select = inputManager.GetGemCellCoords(xMouse, yMouse, index);
	ASSERT_FALSE(select);
}