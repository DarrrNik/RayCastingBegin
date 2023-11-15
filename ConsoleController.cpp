#include "ConsoleController.h"

ConsoleController::ConsoleController() : nScreenWidth(DEFAULT_SCREEN_WIDTH), nScreenHeight(DEFAULT_SCREEN_HEIGHT)
{
	screen = new wchar_t[nScreenWidth * nScreenHeight + 1]; // Cимволы юникода
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;

	//screen[nScreenWidth * nScreenHeight] = '\0';  // Последний символ - окончание строки
	//WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
}

ConsoleController::ConsoleController(int width, int height) : nScreenWidth(width), nScreenHeight(height)
{
	screen = new wchar_t[nScreenWidth * nScreenHeight + 1]; // Cимволы юникода
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;

	//screen[nScreenWidth * nScreenHeight] = '\0';  // Последний символ - окончание строки
	//WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
}

ConsoleController::ConsoleController(ConsoleController& exemp) : nScreenWidth(exemp.nScreenWidth), nScreenHeight(exemp.nScreenHeight)
{
	screen = exemp.screen;
	hConsole = exemp.hConsole;
	dwBytesWritten = exemp.dwBytesWritten;
}

ConsoleController::~ConsoleController()
{
	delete[] screen;
}

void ConsoleController::UpdateFrame()
{
	screen[nScreenWidth * nScreenHeight] = '\0';  // Последний символ - окончание строки
	WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
}
