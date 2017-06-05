#pragma once
#include <windows.h>
#include "Graphics2D.h"

class Screen : public Graphics2D
{
public:
	static Screen& getInstance();

	void resizeToWindow();

	void print();

private:
	Screen();
	~Screen();
	Screen(Screen const&) = delete;
	Screen& operator= (Screen const&) = delete;

	HANDLE stdHandle;
};

