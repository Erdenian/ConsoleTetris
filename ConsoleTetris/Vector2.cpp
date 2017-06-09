#include "Vector2.h"

#include <math.h>

Vector2::Vector2(double x, double y) : x(x), y(y)
{}

bool Vector2::operator==(const Vector2& obj) const
{
	return ((x == obj.x) && (y == obj.y));
}

Vector2 Vector2::operator-(const Vector2& rightVector) const {
	return Vector2(x - rightVector.x, y - rightVector.y);
}

Vector2 Vector2::operator+(const Vector2& rightVector) const {
	return Vector2(x + rightVector.x, y + rightVector.y);
}

inline double Vector2::magnitude()
{
	return sqrt(sqrMagnitude());
}

inline double Vector2::sqrMagnitude()
{
	return x * x + y * y;
}

