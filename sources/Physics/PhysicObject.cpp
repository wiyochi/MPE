#include "PhysicObject.h"

namespace mpe
{
	PhysicObject::PhysicObject() :
		m_resistanceCoeff(0.9f),
		m_weight(1.f),
		m_position(0, 0),
		m_velocity(0, 0),
		m_acceleration(0, 0)
	{
	}

	PhysicObject::PhysicObject(Vector2f pos, float weight, float resCoeff) :
		m_resistanceCoeff(resCoeff),
		m_weight(weight),
		m_position(pos),
		m_velocity(0, 0),
		m_acceleration(0, 0)
	{
	}

	PhysicObject::~PhysicObject()
	{
	}

	void PhysicObject::addForce(Vector2f f)
	{
		m_forces.push_back(f);
	}

	void PhysicObject::update(float dt)
	{
		Vector2f forceSum(0.f, 0.f);
		Vector2f d(0.f, 0.f);

		// TODO: Add gravity after air resistance
		// Gravity
		//this->addForce(Gravity * m_weight);

		// Forces sum
		for (unsigned int i = 0; i < m_forces.size(); i++)
		{
			forceSum += m_forces[i];
		}

		// F = m.a
		m_acceleration = forceSum / m_weight;
		m_forces.clear();

		if (m_acceleration != Vector2f::nullVector)
		{
			//TODO: Faire une fonction d'approximation pour negligé l'acceleration et la vitesse lorsque qu'elle sont petites

			// d = 1/2 * a * t² + v0 * t
			d = 1.f / 2.f * m_acceleration * (float)std::pow(dt, 2) + m_velocity * dt;
			m_velocity = m_acceleration * dt + m_velocity;
		}
		else
		{
			d = m_velocity * dt;
		}

		m_position = m_position + d;
	}


	float PhysicObject::getWeight() const
	{
		return m_weight;
	}

	void PhysicObject::setWeight(float w)
	{
		if (w >= 0)
			m_weight = w;
	}

	Vector2f PhysicObject::getPosition() const
	{
		return m_position;
	}

	void PhysicObject::setPosition(Vector2f pos)
	{
		m_position = pos;
	}

	Vector2f PhysicObject::getVelocity() const
	{
		return m_velocity;
	}

	void PhysicObject::setVelocity(Vector2f vel)
	{
		m_velocity = vel;
	}

	Vector2f PhysicObject::getAcceleration() const
	{
		return m_acceleration;
	}

	float PhysicObject::getResistanceCoeff() const
	{
		return m_resistanceCoeff;
	}

	void PhysicObject::setResistanceCoeff(float resCoeff)
	{
		if (resCoeff > 0)
			m_resistanceCoeff = resCoeff;
	}
}