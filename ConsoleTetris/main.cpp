#include <stdio.h>
#include <windows.h>
#include <WinUser.h>
#include <synchapi.h>
#include "Graphics2D.h"
#include "Screen.h"
#include "Vector2.h"
#include "Scene.h"
#include "GameObject.h"

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
	GameObject hero(Vector2(10, 10), heroGraphics);
	scene.gameObjects.push_back(hero);

	int x = 1, y = 1;

	int carX = 10;
	int carY = 0;

	int i = 0;

	while (true) {
		screen.resizeToWindow();

		Graphics2D background(screen.getWidth(), screen.getHeigth());
		background.fill('e');
		background.setRectangle(1, 1, background.getWidth() - 2, background.getHeigth() - 2, Color('.', '.'));
		background.setRectangle(10, 10, 30, 40, Color('a', 'b'));

		if (GetAsyncKeyState(VK_LEFT)) x--;
		if (GetAsyncKeyState(VK_RIGHT)) x++;
		if (GetAsyncKeyState(VK_UP)) y--;
		if (GetAsyncKeyState(VK_DOWN)) y++;

		if (x < 1) x = 1;
		else if (x + heroGraphics.getWidth() >= screen.getWidth()) x = screen.getWidth() - heroGraphics.getWidth() - 1;
		if (y < 1) y = 1;
		else if (y + heroGraphics.getHeigth() >= screen.getHeigth()) y = screen.getHeigth() - heroGraphics.getHeigth() - 1;

		screen.setImage(0, 0, background);

		screen.drawImage(x, y, heroGraphics);
		screen.print();

		Sleep(100);
		i++;
	}

	system("PAUSE");
	return 0;
}
