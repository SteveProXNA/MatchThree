#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

typedef unsigned char UCHAR;

namespace MatchThree
{
	const short MAX_ROWS = 8;
	const short MAX_COLS = 8;
	const short MAX_GEMS = 5;
	const short NUM_MATCH = 3;

	const short SCREEN_WIDTH = 755;
	const short SCREEN_HEIGHT = 600;

	const short TITLE_STARTX = 322;
	const short TITLE_STARTY = 122;
	const short GEM_STARTX = 320;
	const short GEM_STARTY = 100;
	const short GEM_WIDTH = 45;
	const short GEM_HEIGHT = 45;

	const short GEM_STEP = 5;
	const short MAX_SCREENS = 4;
	const short MAX_STATES = 6;
	const short MAX_AUDIO = 5;
	const short NO_SELECTION = -1;

	const short GAME_OVERX = 365;
	const short GAME_OVERY = 200;

	const short SPLASH_DELAY = 5000;
	const short TITLE_DELAY = 800;
	const short SCORE_IMAGES = 11;
	const short TIMER_IMAGES = 11;

	const short SCORE_POSX = 150;
	const short SCORE_POSY = 150;
	const short CLOCK_POSX = 140;
	const short CLOCK_POSY = 50;

	const char LOG_FILENAME[8] = "log.txt";
	const char CONFIG_FILENAME[11] = "config.txt";
	const char BOARD_FILENAME[10] = "board.txt";

	enum ConfigType
	{
		FPS_CONFIG,
		FULL_SCREEN_CONFIG,
		CLOCK_LENGTH_CONFIG,
		GAME_MODE_CONFIG,
		AUDIO_SET_CONFIG,
		GEM_ANIMATE_DELAY
	};

	enum ScreenType
	{
		SPLASH_SCREEN,
		TITLE_SCREEN,
		PLAY_SCREEN,
		OVER_SCREEN
	};

	enum StateType
	{
		ONE_SELECT_STATE,
		TWO_SELECT_STATE,
		SWAP_FORWARD_STATE,
		SWAP_BACK_STATE,
		REPLENISH_STATE,
		DROP_GEMS_STATE,
	};

	enum GameType
	{
		TIMED_GAME,
		UNTIMED_GAME
	};

	enum GemType
	{
		EMPTY_GEM,
		BLUE_GEM,
		GREEN_GEM,
		PURPLE_GEM,
		RED_GEM,
		YELLOW_GEM,
		BLUE_LARGE_GEM,
		GREEN_LARGE_GEM,
		PURPLE_LARGE_GEM,
		RED_LARGE_GEM,
		YELLOW_LARGE_GEM,
	};

	enum DirectionType
	{
		LEFT_DIRECTION,
		RIGHT_DIRECTION,
		UP_DIRECTION,
		DOWN_DIRECTION
	};

	enum AudioType
	{
		GO_AUDIO,
		BUZZ_AUDIO,
		CLICK_AUDIO,
		MARBLE_AUDIO,
		OVER_AUDIO
	};

	enum MouseButtonType
	{
		NO_BUTTON_DOWN,
		LEFT_BUTTON_DOWN,
		RIGHT_BUTTON_DOWN
	};
}

#endif//_CONSTANTS_H_