#include "Vector3.h"
#include <math.h>

Vector3::Vector3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
	
}

Vector3 Vector3::operator-(const Vector3& rightVector) const {
	return Vector3(x - rightVector.x, y - rightVector.y, z - rightVector.z);
}

Vector3 Vector3::operator+(const Vector3& rightVector) const {
	return Vector3(x + rightVector.x, y + rightVector.y, z + rightVector.z);
}

void Vector3::operator-=(const Vector3& rightVector) {
	x -= rightVector.x;
	y -= rightVector.y;
	z -= rightVector.z;
}

void Vector3::operator+=(const Vector3& rightVector) {
	x += rightVector.x;
	y += rightVector.y;
	z += rightVector.z;
}

bool Vector3::operator==(const Vector3& rightVector) const {
	return (x == rightVector.x && y == rightVector.y && z == rightVector.z);
}

inline double Vector3::magnitude()
{
	return sqrt(sqrMagnitude());
}

inline double Vector3::sqrMagnitude()
{
	return x * x + y * y + z * z;
}