#include "pch.h"
#include "Log.h"
#include <Windows.h>
#include <ctime>

namespace Engine {

	Log* Log::s_Logger;

	void Log::Init()
	{
		s_Logger = new Log;
		s_Logger->m_ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		s_Logger->m_Separator = ' ';
		EG_STATE("Initialized Log!");
	}

	void Log::SetColor(int color)
	{
		SetConsoleTextAttribute(GetLogger()->m_ConsoleHandle, color);
	}

	void Log::PrintTime()
	{
		time_t now = time(0);
		tm* lctime = localtime(&now);
		auto h = lctime->tm_hour;
		auto m = lctime->tm_min;
		auto s = lctime->tm_sec;

		std::cout << '[' << (h>9?"\0" : "0") << h << ':' << (m>9 ? "\0" : "0") << m << ':' << (s>9 ? "\0" : "0") << s << "] ";
	}
}