#pragma once
#include "GameObject.h"
#include <vector>

class Scene
{
public:
	~Scene();

	void run();

	std::vector<GameObject*> gameObjects;
};

