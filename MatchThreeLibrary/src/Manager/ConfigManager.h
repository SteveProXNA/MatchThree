#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_
//#pragma once

namespace MatchThree
{
    class ConfigManager
    {
    public:
        ConfigManager()     {}
        ~ConfigManager()    {}

        void Init();
        int GetConfig(const char index)
        {
            return m_iConfig[index];
        }

    private:
        void LogConfiguration();
        short m_iConfig[10];
    };
}

#endif//_CONFIG_MANAGER_H_