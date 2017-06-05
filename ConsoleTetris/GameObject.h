#pragma once
#include "Vector2.h"
#include "Graphics2D.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	Vector2 position;
	Graphics2D image;
};

