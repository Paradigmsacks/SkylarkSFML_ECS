#pragma  once
#include "stdafx.h"
#include "Vector.h"
namespace Skylark
{
	Vector::Vector()
	{
		Vector(0.0f, 0.0f);
	}

	Vector::Vector(sf::Vector2f& vec)
	{
		Vector(vec.x, vec.y);
	}

	Vector::Vector(float x, float y)
	{
		X = x;
		Y = y;
	}

	sf::Vector2f Vector::toSF()
	{
		return sf::Vector2f(X, Y);
	}

	sf::Transform Vector::toTransform(float angle)
	{
		sf::Transform t;
		t.rotate(angle);
		t.translate(X, Y);
		return t;
	}
}