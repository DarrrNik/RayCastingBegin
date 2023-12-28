#pragma once
#include <Windows.h>

#define DEFAULT_SCREEN_WIDTH (120)
#define DEFAULT_SCREEN_HEIGHT (40)

static class ConsoleController
{
public:
	static const int nScreenWidth = DEFAULT_SCREEN_WIDTH;
	static const int nScreenHeight = DEFAULT_SCREEN_HEIGHT;
	static wchar_t* screen;

	/*ConsoleController();
	ConsoleController(int width, int height);
	ConsoleController(ConsoleController& exemp);*/
	//~ConsoleController();

	//void UpdateFrame();
	
private:
	HANDLE hConsole;
	DWORD dwBytesWritten;
};
