#pragma once
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "../Basics/basics.h"

namespace mpe
{
	class PhysicObject
	{
	protected:
		float m_resistanceCoeff;
		float m_weight;
		Vector2f m_position;
		Vector2f m_velocity;
		Vector2f m_acceleration;
		std::vector<Vector2f> m_forces;

	public:
		PhysicObject();
		PhysicObject(Vector2f pos, float weight = 1.f, float resCoeff = 0.9f);
		~PhysicObject();

		void addForce(Vector2f f);
		virtual void update(float dt);

		virtual float getCrossSection() = 0; // Each PhysicObject has to calculate or just give a crossSection

		// Accessors
		float getWeight() const;
		void setWeight(float w);
		Vector2f getPosition() const;
		void setPosition(Vector2f pos);
		Vector2f getVelocity() const;
		void setVelocity(Vector2f vel);
		Vector2f getAcceleration() const;
		float getResistanceCoeff() const;
		void setResistanceCoeff(float resCoeff);
	};
}