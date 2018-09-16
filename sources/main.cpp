#include <iostream>
#include <time.h>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "Display/Scene.h"
#include "Basics/basics.h"
#include "Physics/PhysicManager.h"
#include "Display/CircleDrawable.h"

//mpe::Vector2f inputForForce(sf::Event evt, int mode);

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	mpe::PhysicManager* manager = new mpe::PhysicManager();

	CircleDrawable* circle = new CircleDrawable({ 100, 100 }, 10.f, 30.f);
	manager->addObject(circle);

	std::chrono::time_point<std::chrono::system_clock> time1, time2;
	time1 = std::chrono::system_clock::now();
	float elapsedSeconds = 0;

	mpe::Vector2f force;
	sf::Font font;
	font.loadFromFile("resources/font/unispace rg.ttf");
	sf::Text forceText;
	forceText.setFont(font);
	forceText.setCharacterSize(10);
	forceText.setFillColor(sf::Color::White);

	std::stringstream ss;
	ss << "force: " << force;
	forceText.setString(ss.str());
	ss.str(std::string());

	forceText.setPosition({ 0, window.getSize().y - forceText.getGlobalBounds().height });

	//int m = 0;

	// TODO: demeler le bordel pour tester

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
					force.x = -0.5f;
				else if (event.key.code == sf::Keyboard::Right)
					force.x = 0.5f;
				else if (event.key.code == sf::Keyboard::Up)
					force.y = -0.5f;
				else if (event.key.code == sf::Keyboard::Down)
					force.y = 0.5f;
				circle->addForce(force);
			}
		}

		ss << "force: " << force;
		forceText.setString(ss.str());
		ss.str(std::string());
		force = mpe::Vector2f::nullVector;

		time2 = std::chrono::system_clock::now();
		elapsedSeconds = std::chrono::duration_cast<std::chrono::nanoseconds>(time2 - time1).count();
		time1 = time2;

		elapsedSeconds /= 1000000;

		// Updates
		manager->update(elapsedSeconds);

		// Clear
		window.clear();

		// Draw
		window.draw(*circle);
		window.draw(forceText);

		// Display
		window.display();
	}

	return 0;
}

//mpe::Vector2f inputForForce(sf::Event evt, int mode)
//{
//	mpe::Vector2f force;
//	if (mode == 0)
//	{
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//			force.x -= 0.01f;
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//			force.x += 0.01f;
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//			force.y -= 0.01f;
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//			force.y += 0.01f;
//	}
//	else
//	{
//		if (evt.key.code == sf::Keyboard::Left)
//			force.x = -0.5f;
//		else if (evt.key.code == sf::Keyboard::Right)
//			force.x = 0.5f;
//		else if (evt.key.code == sf::Keyboard::Up)
//			force.y = -0.5f;
//		else if (evt.key.code == sf::Keyboard::Down)
//			force.y = 0.5f;
//	}
//
//	return force;
//}
//			else if (event.type == sf::Event::KeyPressed)
//			{
//				force = inputForForce(event, m);
//			}
//			else if (event.type == sf::Event::KeyReleased)
//			{
//				if (m == 1)
//				{
//					circle->addForce(force);
//					force = mpe::Vector2f::nullVector;
//					ss << "force: " << force;
//					forceText.setString(ss.str());
//					ss.str(std::string());
//				}
//				else if (event.key.code == sf::Keyboard::Enter)
//				{
//					circle->addForce(force);
//					force = mpe::Vector2f::nullVector;
//					ss << "force: " << force;
//					forceText.setString(ss.str());
//					ss.str(std::string());
//				}
//				else if (event.key.code == sf::Keyboard::M)
//				{
//					m = (m + 1) % 2;
//				}
//			}