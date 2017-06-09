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
#include "EnemyScript.h"
#include "PlayerScript.h"
#include "ScoreScript.h"

int main()
{
	Graphics2D car(3, 4);
	car.fill(219);
	car.setColor(0, 0, Color(' ', ' '));
	car.setColor(2, 0, Color(' ', ' '));
	car.setColor(0, 2, Color(' ', ' '));
	car.setColor(2, 2, Color(' ', ' '));
	car.setColor(1, 3, Color(' ', ' '));


	Screen& screen = Screen::getInstance();
	Scene scene;

	Graphics2D background(screen.getWidth(), screen.getHeigth());

	background.setRectangle(21, 1, 1, background.getHeigth() - 2, Color('|', '|'));
	background.setRectangle(21 + (car.getWidth() + 1), 1, 1, background.getHeigth() - 2, Color('|', '|'));
	background.setRectangle(21 + 2 * (car.getWidth() + 1), 1, 1, background.getHeigth() - 2, Color('|', '|'));
	GameObject backgroundObj(Vector2(0, 0), background);

	scene.gameObjects.push_back(&backgroundObj);

	GameObject player(Vector2(22 + car.getWidth() + 1, screen.getHeigth() - 5), car);
	player.addScript(new PlayerScript);
	scene.gameObjects.push_back(&player);

	GameObject enemy(Vector2(22, 0), car);
	enemy.addScript(new EnemyScript);
	scene.gameObjects.push_back(&enemy);

	GameObject enemy1(Vector2(22, 10), car);
	enemy1.addScript(new EnemyScript);
	scene.gameObjects.push_back(&enemy1);

	GameObject enemy2(Vector2(22, 20), car);
	enemy2.addScript(new EnemyScript);
	scene.gameObjects.push_back(&enemy2);

	GameObject score(Vector2(40, 10), Graphics2D(20, 1));
	score.addScript(new ScoreScript);
	scene.gameObjects.push_back(&score);

	Graphics2D foreground(screen.getWidth(), screen.getHeigth());
	foreground.fill('o');
	foreground.setRectangle(1, 1, foreground.getWidth() - 2, foreground.getHeigth() - 2, Color(' ', ' '));
	GameObject foregObj(Vector2(0, 0), foreground);
	scene.gameObjects.push_back(&foregObj);

	scene.run();

	system("PAUSE");
	return 0;
}
