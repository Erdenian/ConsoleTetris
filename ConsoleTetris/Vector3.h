#pragma once
class Vector3
{
public:
	Vector3(double x, double y, double z);
	~Vector3();
	double x, y, z;
	Vector3 operator-(const Vector3& rightVector) const;
	Vector3 operator+(const Vector3& rightVector) const;
	bool operator==(const Vector3& rightVector) const;

	inline double magnitude();
	inline double sqrMagnitude();
};

