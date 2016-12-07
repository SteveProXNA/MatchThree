#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <SDL/SDL.h>
#include "Manager/AnimateManager.h"
#include "Manager/AudioManager.h"
#include "Manager/BoardManager.h"
#include "Manager/ClockManager.h"
#include "Manager/ConfigManager.h"
#include "Manager/ContentManager.h"
#include "Manager/InputManager.h"
#include "Manager/LogManager.h"
#include "Manager/ScoreManager.h"
#include "Manager/ScreenManager.h"

namespace MatchThree
{
	class Engine
	{
	public:
		static Engine& Instance()
		{
			static Engine instance;
			return instance;
		}

		void Init();
		void Play();
		void Quit();

		AnimateManager& AnimateManager()    { return animateManager; }
		AudioManager&   AudioManager()      { return audioManager; }
		BoardManager&   BoardManager()      { return boardManager; }
		ClockManager&   ClockManager()      { return clockManager; }
		ConfigManager&  ConfigManager()     { return configManager; }
		ContentManager& ContentManager()    { return contentManager; }
		InputManager&   InputManager()      { return inputManager; }
		LogManager&     LogManager()        { return logManager; }
		ScoreManager&   ScoreManager()      { return scoreManager; }
		ScreenManager&  ScreenManager()     { return screenManager; }

		SDL_Surface* const GetScreen()      { return screen; }
		void SetScreen();

	private:
		MatchThree::AnimateManager    animateManager;
		MatchThree::AudioManager      audioManager;
		MatchThree::BoardManager      boardManager;
		MatchThree::ClockManager      clockManager;
		MatchThree::ConfigManager     configManager;
		MatchThree::ContentManager    contentManager;
		MatchThree::InputManager      inputManager;
		MatchThree::LogManager        logManager;
		MatchThree::ScreenManager     screenManager;
		MatchThree::ScoreManager      scoreManager;

		// Main game screen.
		SDL_Surface* screen;
		bool m_bFullScreen;
	};
}

#endif//_ENGINE_H_