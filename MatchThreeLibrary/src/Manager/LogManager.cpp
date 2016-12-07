#include "LogManager.h"
#include "../Constants.h"
#include <stdarg.h>

namespace MatchThree
{
	void LogManager::Init()
	{
		log.open(LOG_FILENAME);
	}

	void LogManager::Quit()
	{
		log.close();
	}

	void LogManager::Write(const char* format, ...)
	{
		va_list args;
		va_start(args, format);
		int bufferLen = _vscprintf(format, args) + 1;
		char *buffer = (char *) malloc(bufferLen);
		strncpy_s(buffer, bufferLen, "", sizeof(char));
		vsprintf_s(buffer + sizeof(char) - 1, bufferLen, format, args);
		log << buffer << flush;
		free(buffer);
	}

}