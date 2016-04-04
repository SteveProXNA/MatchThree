#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_
//#pragma once

#include "../Constants.h"

namespace MatchThree
{
    class AudioManager
    {
    public:
        AudioManager()  {}
        ~AudioManager() {}

        void Init(bool audioSet);
        void PlayAudio(AudioType audioType);

    private:
        bool audioSet;
    };
}

#endif//_AUDIO_MANAGER_H_