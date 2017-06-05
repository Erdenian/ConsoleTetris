#pragma once
class Vector2
{
public:
	Vector2(double x, double y);

	bool operator==(const Vector2& obj) const;

	inline double magnitude();
	inline double sqrMagnitude();

	double x, y;
};

