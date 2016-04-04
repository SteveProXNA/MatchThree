#include "Main.h"
//#pragma once

//#include <SDL/SDL.h>
//#include "Engine.h"

//using namespace MatchThree;

int main(int argc, char* argv[])
{
    Engine::Instance().Init();
    Engine::Instance().Play();
    Engine::Instance().Quit();

    return 0;
}