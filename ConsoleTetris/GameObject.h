#pragma once
#include "Graphics2D.h"
#include <vector>
#include "Vector2.h"

class Script;

class GameObject
{
	friend class Scene;

public:
	GameObject(Vector2 position, Graphics2D graphics);
	~GameObject();

	void addScript(Script* script);

	Vector2 position;
	Graphics2D graphics;

private:
	std::vector<Script*> scripts;
};

class Script
{
	friend class GameObject;

public:
	virtual void onStart() = 0;
	virtual void onUpdate() = 0;

	GameObject* getGameObject()
	{
		return gameObject;
	}

private:
	GameObject* gameObject;
};
