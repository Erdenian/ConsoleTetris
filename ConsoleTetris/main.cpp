#include <stdio.h>
#include <windows.h>
#include <WinUser.h>
#include <synchapi.h>
#include "Graphics2D.h"
#include "Screen.h"
#include "Vector2.h"
#include "Scene.h"
#include "GameObject.h"
#include "TestScript.h"

int main()
{
	Graphics2D heroGraphics(3, 4);
	heroGraphics.fill(219);
	heroGraphics.setColor(0, 0, Color(' ', ' '));
	heroGraphics.setColor(2, 0, Color(' ', ' '));
	heroGraphics.setColor(0, 2, Color(' ', ' '));
	heroGraphics.setColor(2, 2, Color(' ', ' '));
	heroGraphics.setColor(1, 3, Color(' ', ' '));

	Screen& screen = Screen::getInstance();
	Scene scene;

	GameObject* hero = new GameObject(Vector2(10, 10), heroGraphics);
	Script* s = new TestScript;
	hero->addScript(s);
	scene.gameObjects.push_back(hero);

	GameObject* hero1 = new GameObject(Vector2(0, 0), heroGraphics);
	Script* s1 = new TestScript;
	hero1->addScript(s1);
	scene.gameObjects.push_back(hero1);

	scene.run();

	system("PAUSE");
	return 0;
}
