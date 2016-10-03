#pragma once
#include <SFML/Graphics.hpp>
namespace Skylark
{
	class Vector
	{
	public:
		float X;
		float Y;

		//Constructors
		Vector();
		Vector(sf::Vector2f& vec);
		Vector(float x, float y);

		//Conversions
		sf::Vector2f toSF();
		sf::Transform toTransform(float angle);
	};
}
