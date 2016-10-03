#pragma once
#include "../ECS/Component.h"
#include <SFML/Graphics.hpp>
namespace Skylark
{
	class SpriteComponent : public Component
	{
	public:
		SpriteComponent() {};
		~SpriteComponent() {};
		void setTexture(sf::Texture* tex)
		{
			mSprite.setTexture(*tex);
		};
		sf::Sprite& getSprite()
		{
			return mSprite;
		}
	private:
		sf::Sprite mSprite;
	};
}