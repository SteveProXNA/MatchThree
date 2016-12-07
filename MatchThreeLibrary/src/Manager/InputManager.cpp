#include "InputManager.h"
#include "../Engine.h"
#include <SDL/SDL.h>

namespace MatchThree
{
	void InputManager::Init()
	{
		prevMouseButton = NO_BUTTON_DOWN;
	}

	void InputManager::Update()
	{
		// Reset current button each time.
		currMouseButton = NO_BUTTON_DOWN;
		if (SDL_GetMouseState(&xMouse, &yMouse) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			currMouseButton = LEFT_BUTTON_DOWN;
		}
		else if (SDL_GetMouseState(&xMouse, &yMouse) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			currMouseButton = RIGHT_BUTTON_DOWN;
		}

		// Determine if any button clicked just once.
		MouseButtonType mouseButton = NO_BUTTON_DOWN;
		if (prevMouseButton != currMouseButton)
		{
			mouseButton = currMouseButton;
		}

		prevMouseButton = currMouseButton;
		currMouseButton = mouseButton;
	}


	bool InputManager::GetGemCell(UCHAR& index)
	{
		return GetGemCellCoords(xMouse, yMouse, index);
	}

	bool InputManager::GetGemCellCoords(int xMouse, int yMouse, UCHAR& index)
	{
		// Method used for unit testing.
		short width = GEM_STARTX + MAX_COLS * GEM_WIDTH;
		short height = GEM_STARTY + MAX_ROWS * GEM_HEIGHT;

		// Hit test outside square that hosts gems.
		if (xMouse < GEM_STARTX || yMouse < GEM_STARTY || xMouse > width || yMouse > height)
		{
			return false;
		}

		// Hit test inside: calculate which cell hit.
		short xTmp = xMouse - GEM_STARTX;
		short yTmp = yMouse - GEM_STARTY;

		short col = xTmp / GEM_WIDTH;
		short row = yTmp / GEM_HEIGHT;

		index = row * MAX_ROWS + col;
		return true;
	}

}