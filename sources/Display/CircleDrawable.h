#pragma once
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "../Physics/Circle.h"

class CircleDrawable : public mpe::Circle, public sf::Drawable
{
private:
	sf::CircleShape m_shape;
	sf::Text m_info;
	sf::Font m_font;

public:
	CircleDrawable();
	CircleDrawable(mpe::Vector2f pos, float radius, float weight = 1.f);
	~CircleDrawable();
	void update(float dt);

	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

