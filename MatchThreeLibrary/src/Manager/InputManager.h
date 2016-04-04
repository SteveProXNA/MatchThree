#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_
//#pragma once

#include "../Constants.h"

namespace MatchThree
{
    class InputManager
    {
    public:
        InputManager()  {}
        ~InputManager() {}

        void Init();
        void Update();

        bool IsMouseButton(MouseButtonType mouseButton) { return mouseButton == currMouseButton; }
        bool GetGemCell(UCHAR& index);
        bool GetGemCellCoords(int xMouse, int yMouse, UCHAR& index);

        int GetMouseX() const { return xMouse; }
        int GetMouseY() const { return yMouse; }

    private:
        MouseButtonType prevMouseButton;
        MouseButtonType currMouseButton;
        int xMouse;
        int yMouse;
    };
}

#endif//_INPUT_MANAGER_H_