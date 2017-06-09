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
		GameObject* player = gameObjects[1];
		for (int i = 2; i < 5; i++) {
			GameObject* gameObject = gameObjects[i];
			if (gameObject->position.y >= player->position.y - player->graphics.getHeigth() + 1 && gameObject->position.x == player->position.x) Sleep(1000000);
		}

		//screen.resizeToWindow();
		screen.clear();
		for (int i = 0; i < gameObjects.size(); i++) {
			GameObject* gameObject = gameObjects[i];
			screen.drawImage(gameObject->position.x, gameObject->position.y, gameObject->graphics);
		}
		screen.print();
		Sleep(60);
	}
}
