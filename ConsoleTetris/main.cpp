#include <stdio.h>
#include <windows.h>
#include <WinUser.h>
#include <synchapi.h>
#include "Graphics2D.h"
#include "Screen.h"
#include "Vector2.h"

/*
 8 
888
 8
8 8
*/

int main()
{
	//setlocale(LC_ALL, "RUSSIAN");
	Screen& screen = Screen::getInstance();

	/*Graphics2D hero(3, 3);
	hero.fill('0');
	hero.setColor(0, 0, Color(' ', ' '));
	hero.setColor(0, 2, Color(' ', ' '));
	hero.setColor(2, 0, Color(' ', ' '));
	hero.setColor(2, 2, Color(' ', ' '));*/

	Graphics2D hero(3, 4);
	hero.fill(219);
	hero.setColor(0, 0, Color(' ', ' '));
	hero.setColor(2, 0, Color(' ', ' '));
	hero.setColor(0, 2, Color(' ', ' '));
	hero.setColor(2, 2, Color(' ', ' '));
	hero.setColor(1, 3, Color(' ', ' '));

	int x = 1, y = 1;

	int carX = 10;
	int carY = 0;

	std::string text = "Kirill negodniy\ntest test   \n   test test  ";

	int i = 0;

	Vector2 v1(1, 2);
	Vector2 v2(1, 2);
	Vector2 v3(2, 3);

	if (v1 == v2) printf("aaa");
	if (v1 == v3) printf("bbb");

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

		/*if (x < 1) x = 1;
		else if (x + hero.getWidth() >= screen.getWidth()) x = screen.getWidth() - hero.getWidth() - 1;
		if (y < 1) y = 1;
		else if (y + hero.getHeigth() >= screen.getHeigth()) y = screen.getHeigth() - hero.getHeigth() - 1;*/

		/*screen.setColor(0, 0, Color((char) 120, (char) 120));
		screen.setColor(screen.getWidth(), 0, Color((char) 120, (char) 120));
		screen.setColor(0, screen.getHeigth(), Color((char) 120, (char) 120));
		screen.setColor(screen.getWidth(), screen.getHeigth(), Color((char) 120, (char) 120));*/

		screen.setImage(0, 0, background);

		/*screen.drawImage(carX, carY % (screen.getHeigth() + 4) - 4, hero);
		screen.drawImage(carX + 3, (carY + 10) % (screen.getHeigth() + 4) - 4, hero);
		screen.drawImage(carX + 3, (carY + 20) % (screen.getHeigth() + 4) - 4, hero);*/
		carY++;

		//screen.drawImage(x, y, hero);
		screen.setText(x, y, text);
		//screen.setColor(x, y, Color('a', 'a'));
		screen.print();

		Sleep(100);
		printf("%d", i);
		i++;
	}

	system("PAUSE");
	return 0;
}