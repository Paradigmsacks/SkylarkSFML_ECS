#pragma once
#include "../ECS/Component.h"
#include <SFML/Graphics.hpp>
namespace sp
{
	struct SpriteComponent : public Component
	{
		sf::Sprite sprite;
	};
}