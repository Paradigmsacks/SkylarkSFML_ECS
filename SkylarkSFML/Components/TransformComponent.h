#pragma once
#include "stdafx.h"
#include "../ECS/Component.h"
#include <SFML/Graphics.hpp>
#include "../Types/Vector.h"
namespace Skylark
{
	class TransformComponent : public Component
	{
	public:
		TransformComponent() {};
		void move(Vector v) {
			mPosition.X += v.X;
			mPosition.Y += v.Y;

		};
		void rotate(float angle) {};
		void setPosition(Vector v) {};
		Vector getPostion() {
			return mPosition;
		}
	private:
		float mAngle;
		Vector mPosition;
	};




}