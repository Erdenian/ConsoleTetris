#include "Color.h"

Color::Color(char left, char right)
{
	this->left = left;
	this->right = right;
}

char Color::getLeft()
{
	return left;
}

char Color::getRight()
{
	return right;
}
