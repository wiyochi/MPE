#include "basics.h"

namespace mpe
{
	Vector2f Vector2f::nullVector(0.f, 0.f);

	Vector2f::Vector2f() :
		x(0),
		y(0)
	{
	};

	Vector2f::Vector2f(float _x, float _y) :
		x(_x),
		y(_y)
	{
	}

	Vector2f::Vector2f(int _x, int _y) :
		x(_x),
		y(_y)
	{
	}

	Vector2f::Vector2f(const Vector2f& v) :
		x(v.x),
		y(v.y)
	{
	}

	Vector2f::Vector2f(int t[2]) :
		x(t[0]),
		y(t[1])
	{
	}

	Vector2f::Vector2f(float t[2]) :
		x(t[0]),
		y(t[1])
	{
	}

	Vector2f & Vector2f::operator=(const Vector2f & v)
	{
		if (&v != this)
		{
			x = v.x;
			y = v.y;
		}
		return *this;
	}

	Vector2f & Vector2f::operator=(float f)
	{
		x = f;
		y = f;
		return *this;
	}

	Vector2f & Vector2f::operator+=(const Vector2f & v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2f & Vector2f::operator-=(const Vector2f & v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	bool operator==(const Vector2f & v1, const Vector2f & v2)
	{
		return ((v1.x == v2.x) && (v1.y == v2.y));
	}

	bool operator!=(const Vector2f & v1, const Vector2f & v2)
	{
		return !((v1.x == v2.x) && (v1.y == v2.y));
	}

	Vector2f operator+(const Vector2f & v1, const Vector2f & v2)
	{
		return Vector2f(v1.x + v2.x, v1.y + v2.y);
	}

	Vector2f operator-(const Vector2f & v1, const Vector2f & v2)
	{
		return Vector2f(v1.x - v2.x, v1.y - v2.y);
	}

	float operator*(const Vector2f & v1, const Vector2f & v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	Vector2f operator*(const Vector2f & v1, const int & mul)
	{
		float m = mul;
		return Vector2f(v1.x * m, v1.y * m);
	}

	Vector2f operator*(const int & mul, const Vector2f & v1)
	{
		float m = mul;
		return Vector2f(v1.x * m, v1.y * m);
	}

	Vector2f operator*(const Vector2f & v1, const float & mul)
	{
		return Vector2f(v1.x * mul, v1.y * mul);
	}

	Vector2f operator*(const float & mul, const Vector2f & v1)
	{
		return Vector2f(v1.x * mul, v1.y * mul);
	}

	Vector2f operator/(const Vector2f & v1, const int & div)
	{
		float d = div;
		return Vector2f(v1.x / d, v1.y / d);
	}

	Vector2f operator/(const int & div, const Vector2f & v1)
	{
		float d = div;
		return Vector2f(v1.x / d, v1.y / d);
	}

	Vector2f operator/(const Vector2f & v1, const float & div)
	{
		return Vector2f(v1.x / div, v1.y / div);
	}

	Vector2f operator/(const float & div, const Vector2f & v1)
	{
		return Vector2f(v1.x / div, v1.y / div);
	}

	std::ostream & operator<<(std::ostream & O, const Vector2f & v)
	{
		O << "(" << v.x << "," << v.y << ")";
		return O;
	}

	Vector2f powf(const Vector2f & v, const int & exp)
	{
		return Vector2f((float)std::pow(v.x, exp), (float)std::pow(v.y, exp));
	}
}