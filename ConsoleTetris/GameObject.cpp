#include "GameObject.h"

GameObject::GameObject(Vector2 position, Graphics2D graphics) : position(position), graphics(graphics)
{}

GameObject::~GameObject()
{
	for (int i = 0; i < scripts.size(); i++) {
		delete scripts[i];
	}
}
