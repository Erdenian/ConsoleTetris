#include "Scene.h"

void Scene::run()
{
	for (int i = 0; i < gameObjects.size(); i++) {
		GameObject gameObject = gameObjects[i];
		for (int j = 0; j < gameObject.scripts.size(); j++) {
			gameObject.scripts[j]->onStart();
		}
	}

	while (true) {
		for (int i = 0; i < gameObjects.size(); i++) {
			GameObject gameObject = gameObjects[i];
			for (int j = 0; j < gameObject.scripts.size(); j++) {
				gameObject.scripts[j]->onUpdate();
			}
		}
	}
}
