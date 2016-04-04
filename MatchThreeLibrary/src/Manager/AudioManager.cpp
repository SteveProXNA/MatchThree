#include "AudioManager.h"
#include <string>

#ifdef WIN32
#include <Windows.h>
#endif

using namespace std;

namespace MatchThree
{
    wstring root = L"content/audio/";
    wstring filenames[MAX_AUDIO] = { L"GO.wav", L"Buzz.wav", L"Click.wav", L"Marble.wav", L"GameOver.wav" };

    void AudioManager::Init(bool audioSet)
    {
        this->audioSet = audioSet;
    }

    void AudioManager::PlayAudio(AudioType audioType)
    {
        if (audioSet)
        {
            return;
        }

        wstring filename = filenames[audioType];
        wstring sound = root + filename;

        // Not keen on conditional compilation but only localized here, at least.
#ifdef WIN32
        PlaySound(sound.c_str(), NULL, SND_FILENAME | SND_ASYNC);
#endif
    }

}