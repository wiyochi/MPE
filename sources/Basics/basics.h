#pragma once
#include <iostream>
#include <cmath>

namespace mpe
{
	struct Vector2f
	{
		Vector2f();
		Vector2f(float _x, float _y);
		Vector2f(int _x, int _y);
		Vector2f(const Vector2f& v);
		Vector2f(int t[2]);
		Vector2f(float t[2]);
		Vector2f& operator=(const Vector2f& v);
		Vector2f& operator=(float f);
		Vector2f& operator+=(const Vector2f& v);
		Vector2f& operator-=(const Vector2f& v);

		float x;
		float y;

		static Vector2f nullVector;

	private:
		friend bool operator==(const Vector2f& v1, const Vector2f& v2);
		friend bool operator!=(const Vector2f& v1, const Vector2f& v2);
		friend Vector2f operator+(const Vector2f& v1, const Vector2f& v2);
		friend Vector2f operator-(const Vector2f& v1, const Vector2f& v2);
		friend float operator*(const Vector2f& v1, const Vector2f& v2);
		friend Vector2f operator*(const Vector2f& v1, const int& mul);
		friend Vector2f operator*(const int& mul, const Vector2f& v1);
		friend Vector2f operator*(const Vector2f& v1, const float& mul);
		friend Vector2f operator*(const float& mul, const Vector2f& v1);
		friend Vector2f operator/(const Vector2f& v1, const int& div);
		friend Vector2f operator/(const int& div, const Vector2f& v1);
		friend Vector2f operator/(const Vector2f& v1, const float& div);
		friend Vector2f operator/(const float& div, const Vector2f& v1);
		friend std::ostream& operator<<(std::ostream& O, const Vector2f& v);
		friend Vector2f powf(const Vector2f& v, const int& exp);
	};

	 bool operator==(const Vector2f& v1, const Vector2f& v2);
	 bool operator!=(const Vector2f& v1, const Vector2f& v2);
	 Vector2f operator+(const Vector2f& v1, const Vector2f& v2);
	 Vector2f operator-(const Vector2f& v1, const Vector2f& v2);
	 float operator*(const Vector2f& v1, const Vector2f& v2);
	 Vector2f operator*(const Vector2f& v1, const int& mul);
	 Vector2f operator*(const int& mul, const Vector2f& v1);
	 Vector2f operator*(const Vector2f& v1, const float& mul);
	 Vector2f operator*(const float& mul, const Vector2f& v1);
	 Vector2f operator/(const Vector2f& v1, const int& div);
	 Vector2f operator/(const int& div, const Vector2f& v1);
	 Vector2f operator/(const Vector2f& v1, const float& div);
	 Vector2f operator/(const float& div, const Vector2f& v1);
	 std::ostream& operator<<(std::ostream& O, const Vector2f& v);
	 Vector2f powf(const Vector2f& v, const int& exp);
}