#pragma once
#include "../Basics/basics.h"
#include "PhysicObject.h"

namespace mpe
{
	class Circle : public PhysicObject
	{
	protected:
		float m_radius;

	public:
		Circle();
		Circle(Vector2f pos, float rad, float w = 1.f, float resCoeff = 0.25f);
		~Circle();

		float getCrossSection();
	};
}