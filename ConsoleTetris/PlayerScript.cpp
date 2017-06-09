#include "PlayerScript.h"
#include "GameObject.h"
#include <Windows.h>

void PlayerScript::onStart() {

}

void PlayerScript::onUpdate() {
	GameObject* obj = getGameObject();
	if (GetAsyncKeyState(VK_LEFT) && obj->position.x - obj->graphics.getWidth() > 22) obj->position.x -= obj->graphics.getWidth() + 1;
	if (GetAsyncKeyState(VK_RIGHT) && obj->position.x + obj->graphics.getWidth() < 21 + 2 * (obj->graphics.getWidth() + 1)) obj->position.x += obj->graphics.getWidth() + 1;
}