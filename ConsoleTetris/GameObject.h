#pragma once
#include "Graphics2D.h"
#include <vector>
#include "Vector2.h"

class Script;

class GameObject
{
public:
	GameObject(Vector2 position, Graphics2D graphics);
	~GameObject();

	Vector2 position;
	Graphics2D graphics;
	std::vector<Script*> scripts;
};

class Script
{
public:
	virtual void onAwake() = 0;
	virtual void onStart() = 0;
	virtual void onUpdate() = 0;
	virtual void onFinish() = 0;
	virtual void onDestroy() = 0;

	GameObject* getGameObject()
	{
		return &gameObject;
	}

private:
	GameObject gameObject;
};
