#pragma once
#include <SFML\Graphics.hpp>
namespace Skylark
{
	class Vec2
	{
	public:
		float X;
		float Y;

		//Constructors
		Vec2();
		Vec2(sf::Vector2f& vec);
		Vec2(float x, float y);

		//Conversions
		sf::Vector2f toSF();
		sf::Transform toTransform(float angle);
	};
}