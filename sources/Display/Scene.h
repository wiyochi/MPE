#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Physics/PhysicObject.h"
#include "../Physics/Circle.h"
#include "../Basics/basics.h"

class Scene : public sf::Drawable
{
private:

public:
	Scene();
	~Scene();
	void addCircle(mpe::Vector2f pos, float rad);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

