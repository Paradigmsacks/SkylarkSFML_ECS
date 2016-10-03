#include "stdafx.h"
#include "Vec2.h"
namespace Skylark
{
	Vec2::Vec2()
	{
		Vec2(0.0f, 0.0f);
		int a = 1;
	}

	Vec2::Vec2(sf::Vector2f& vec)
	{
		Vec2(vec.x, vec.y);
	}

	Vec2::Vec2(float x, float y)
	{
		X = x;
		Y = y;
	}

	sf::Vector2f Vec2::toSF()
	{
		return sf::Vector2f(X, Y);
	}

	sf::Transform Vec2::toTransform(float angle)
	{
		sf::Transform t;
		t.rotate(angle);
		t.translate(X, Y);
		return t;
	}
}