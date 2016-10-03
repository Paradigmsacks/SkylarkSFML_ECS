#pragma once
#include <SFML/Graphics.hpp>
namespace sp
{
	class Vec2f
	{
	public:
		float X;
		float Y;


		Vec2f(sf::Vector2f& vec);
		sf::Vector2f toSFML();
		Vec2f();
		~Vec2f();
	};
}

