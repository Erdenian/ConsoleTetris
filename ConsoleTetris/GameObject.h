#pragma once
#include "Graphics2D.h"
#include <vector>

class Script;

class GameObject
{
public:
	GameObject();
	~GameObject();

	//Vector3 position;
	Graphics2D graphics;
	std::vector<Script> scripts;
};

class Script
{
public:
	virtual void onAwake() = 0;
	virtual void onStart() = 0;
	virtual void onUpdate() = 0;
	virtual void onFinish() = 0;
	virtual void onDestroy() = 0;

private:
	GameObject gameObject;
};
