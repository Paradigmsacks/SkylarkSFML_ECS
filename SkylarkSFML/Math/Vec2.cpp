#include "stdafx.h"
#include "Vec2.h"
namespace sp
{
	Vec2::Vec2()
	{
		Vec2(0.0f, 0.0f);
		int a = 1;
	}

	Vec2::Vec2(float x, float y)
	{
		X = x;
		Y = y;
	}
}