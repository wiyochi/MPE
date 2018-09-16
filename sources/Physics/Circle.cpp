#include "Circle.h"

namespace mpe
{
	const float pi = 3.1415926535;

	Circle::Circle() :
		Circle(Vector2f(0, 0), 10, 10)
	{
	}

	Circle::Circle(Vector2f pos, float rad, float w, float resCoeff) :
		PhysicObject(pos, w, resCoeff),
		m_radius(rad)
	{
	}

	Circle::~Circle()
	{
	}

	float Circle::getCrossSection()
	{
		return pi * std::pow(m_radius, 2);
	}
}