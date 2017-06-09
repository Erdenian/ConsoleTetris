#include "TestScript.h"
#include <windows.h>

void TestScript::onStart()
{}

void TestScript::onUpdate()
{
	Vector2* position = &getGameObject()->position;
	*position = *position + Vector2(1, 1);
	Sleep(100);
}
