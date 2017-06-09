#include "TestScript.h"

void TestScript::onUpdate()
{
	Vector2 position = getGameObject()->position;
	position = position + Vector2(1, 1);
}
