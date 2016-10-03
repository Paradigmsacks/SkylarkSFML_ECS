#include "stdafx.h"
#include "Vec2f.h"

namespace sp
{
	Vec2f::Vec2f()
	{
	}

	sp::Vec2f::Vec2f(sf::Vector2f& vec)
	{
		X = vec.x;
		Y = vec.y;
	}

	sf::Vector2f sp::Vec2f::toSFML()
	{
		return sf::Vector2f(X, Y);
	}

	Vec2f::~Vec2f()
	{

	}
}
