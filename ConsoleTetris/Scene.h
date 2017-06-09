#pragma once
#include "GameObject.h"
#include <vector>

class Scene
{
public:
	void run();

	std::vector<GameObject> gameObjects;
};

