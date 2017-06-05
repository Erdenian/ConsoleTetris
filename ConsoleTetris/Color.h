#pragma once
class Color
{
public:
	Color(char left, char right);

	char getLeft();
	char getRight();

private:
	char left, right;
};

