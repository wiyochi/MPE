#include "PhysicManager.h"

namespace mpe
{
	PhysicManager::PhysicManager()
	{
	}

	PhysicManager::~PhysicManager()
	{
	}

	void PhysicManager::addObject(PhysicObject * o)
	{
		m_physicObjects.push_back(o);
	}

	void PhysicManager::update(float dt)
	{
		Vector2f airResistance(0.f, 0.f);

		for (unsigned int i = 0; i < m_physicObjects.size(); i++)
		{
			// If the object has a velocity, we calculate an air resistance and we add it to the object
			if (m_physicObjects[i]->getVelocity() != Vector2f::nullVector)
			{
				airResistance = -1 * m_physicObjects[i]->getResistanceCoeff() * AirDensity *\
					m_physicObjects[i]->getCrossSection() * mpe::powf(m_physicObjects[i]->getVelocity(), 2);

				//std::cout << airResistance << std::endl;

				m_physicObjects[i]->addForce(airResistance);
			}

			m_physicObjects[i]->update(dt);
		}
	}
}