#pragma once

#include <Windows.h>

#define DEFAULT_SCREEN_WIDTH (120)
#define DEFAULT_SCREEN_HEIGHT (40)

class ConsoleController
{
public:
	ConsoleController();
	ConsoleController(int width, int height);
	ConsoleController(ConsoleController& exemp);
	~ConsoleController();

	void UpdateFrame();
	
private:
	int nScreenWidth;
	int nScreenHeight;

	wchar_t* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten;
};
