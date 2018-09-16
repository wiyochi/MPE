#pragma once
#include <vector>
#include "../Basics/basics.h"
#include "PhysicObject.h"

namespace mpe
{
	class PhysicManager
	{
	private:
		float AirDensity = 1;
		std::vector<PhysicObject*> m_physicObjects;

	public:
		PhysicManager();
		~PhysicManager();
		void addObject(PhysicObject* o);
		void update(float dt);
	};
}