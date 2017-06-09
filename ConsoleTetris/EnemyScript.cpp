#include "EnemyScript.h"
#include "Screen.h"

void EnemyScript::onStart() {

}

void EnemyScript::onUpdate() {
	Screen& screen = Screen::getInstance();
	GameObject* object = getGameObject();

	object->position.y += 1;
	if (object->position.y > screen.getHeigth() - 1) {
		object->position.y = 0.0 - object->graphics.getHeigth();
		object->position.x = ((rand() % 2 + 1) < 2) ? 22 : 22 + (object->graphics.getWidth() + 1);
	}
}