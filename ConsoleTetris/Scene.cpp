#include "Scene.h"
#include "Screen.h"

Scene::~Scene()
{
	for (int i = 0; i < gameObjects.size(); i++) {
		delete gameObjects[i];
	}
}

void Scene::run()
{
	Screen& screen = Screen::getInstance();

	/*for (int i = 0; i < gameObjects.size(); i++) {
		GameObject gameObject = gameObjects[i];
		for (int j = 0; j < gameObject.scripts.size(); j++) {
			gameObject.scripts[j]->onStart();
		}
	}*/

	while (true) {
		for (int i = 0; i < gameObjects.size(); i++) {
			GameObject* gameObject = gameObjects[i];
			for (int j = 0; j < gameObject->scripts.size(); j++) {
				gameObject->scripts[j]->onUpdate();
			}
		}

		screen.resizeToWindow();
		screen.clear();
		for (int i = 0; i < gameObjects.size(); i++) {
			GameObject* gameObject = gameObjects[i];
			screen.drawImage(gameObject->position.x, gameObject->position.y, gameObject->graphics);
		}
		screen.print();
	}
}
