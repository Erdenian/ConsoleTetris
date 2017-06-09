#pragma once
#include "GameObject.h"
class ScoreScript :
	public Script
{
public:
	void onStart();
	void onUpdate();
private:
	int score = 0;
};

