#include "ConfigManager.h"
#include "../Constants.h"
#include "../Engine.h"
#include <fstream>

using namespace std;

namespace MatchThree
{
    void LogConfiguration();

    void ConfigManager::Init()
    {
        memset(m_iConfig, 0, sizeof(m_iConfig));

        // Default values.
        m_iConfig[FPS_CONFIG] = 60;
        m_iConfig[FULL_SCREEN_CONFIG] = 1;
        m_iConfig[CLOCK_LENGTH_CONFIG] = 60;
        m_iConfig[GAME_MODE_CONFIG] = 0;
        m_iConfig[AUDIO_SET_CONFIG] = 0;
        m_iConfig[GEM_ANIMATE_DELAY] = 400;
        // Config values.
        std::ifstream myfile;
        myfile.open(CONFIG_FILENAME, std::ifstream::in);

        if (myfile.fail())
        {
            myfile.clear(std::ios::failbit);
            LogConfiguration();
            return;
        }

        // Load configuration.
        char buffer[256];
        char cnt = 0;

        while (!myfile.eof())
        {
            myfile.getline (buffer,100);
            m_iConfig[cnt++] = atoi(buffer);
        }

        myfile.close();
        LogConfiguration();
    }

    void ConfigManager::LogConfiguration()
    {
        // Log all configuration!
        Engine::Instance().LogManager().Write("FPS CONFIG : %d\n", GetConfig(FPS_CONFIG));
        Engine::Instance().LogManager().Write("FULLSCREEN : %d\n", GetConfig(FULL_SCREEN_CONFIG));
        Engine::Instance().LogManager().Write("CLOCK TIME : %d\n", GetConfig(CLOCK_LENGTH_CONFIG));
        Engine::Instance().LogManager().Write("GAME MODE> : %d\n", GetConfig(GAME_MODE_CONFIG));
        Engine::Instance().LogManager().Write("AUDIO SET> : %d\n", GetConfig(AUDIO_SET_CONFIG));
        Engine::Instance().LogManager().Write("ANIMATION> : %d\n", GetConfig(GEM_ANIMATE_DELAY));
    }

}