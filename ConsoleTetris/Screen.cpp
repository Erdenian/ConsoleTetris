#include "Screen.h"

#include <windows.h>
#include <stdio.h>

Screen::Screen() : Graphics2D([&]()->int {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(stdHandle, &csbi);
	return (csbi.srWindow.Right - csbi.srWindow.Left) / 2;
}(), [&]()->int {
	stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(stdHandle, &csbi);
	return csbi.srWindow.Bottom - csbi.srWindow.Top;
}())
{}

Screen::~Screen()
{}

Screen& Screen::getInstance()
{
	static Screen s;
	return s;
}

void Screen::resizeToWindow()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(stdHandle, &csbi);
	int w = (csbi.srWindow.Right - csbi.srWindow.Left) / 2;
	int h = csbi.srWindow.Bottom - csbi.srWindow.Top;
	if ((w != getWidth()) || (h != getHeigth())) system("CLS");
	setSize(w, h);
}

void Screen::print()
{
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(stdHandle, pos);
	Graphics2D::print();
}
