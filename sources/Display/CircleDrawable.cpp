#include "CircleDrawable.h"

CircleDrawable::CircleDrawable()
{
	CircleDrawable(mpe::Vector2f(0, 0), 10);
}

CircleDrawable::CircleDrawable(mpe::Vector2f pos, float radius, float weight) :
	mpe::Circle(pos, radius, weight)
{
	m_shape.setRadius(m_radius);
	m_shape.setPosition({ m_position.x, m_position.y });
	m_shape.setFillColor(sf::Color(255, 255, 255, 150));

	std::string str;
	std::stringstream ss;
	ss << "position: " << m_position << std::endl << "acceleration:" << m_acceleration << std::endl << "weight: " << m_weight;
	str.append(ss.str());

	m_font.loadFromFile("resources/font/unispace rg.ttf");
	m_info.setFont(m_font);
	m_info.setCharacterSize(10);
	m_info.setFillColor(sf::Color::White);
	m_info.setPosition({ 0, 0 });
	m_info.setString(str);
}

CircleDrawable::~CircleDrawable()
{
}

void CircleDrawable::update(float dt)
{
	PhysicObject::update(dt);

	m_shape.setPosition({ m_position.x, m_position.y });

	std::string str;
	std::stringstream ss;
	ss << "position: " << m_position << std::endl\
		<< "velocity:" << m_velocity << std::endl\
		<< "acceleration:" << m_acceleration << std::endl\
		<< "weight: " << m_weight << std::endl\
		<< "resistanceCoeff: " << m_resistanceCoeff << std::endl\
		<< "crossSection: " << getCrossSection();
	str.append(ss.str());
	m_info.setString(str);
}

void CircleDrawable::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_shape, states);
	target.draw(m_info, states);
}
