#pragma once
class Vector2
{
public:
	Vector2(double x, double y);

	bool operator==(const Vector2& obj) const;

	inline double magnitude();
	inline double sqrMagnitude();

	Vector2 operator-(const Vector2& rightVector) const;
	Vector2 operator+(const Vector2& rightVector) const;
	void operator-=(const Vector2& rightVector);
	void operator+=(const Vector2& rightVector);

	double x, y;
};

