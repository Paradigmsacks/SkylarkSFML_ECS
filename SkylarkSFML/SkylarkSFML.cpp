// SkylarkSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "ECS/Entity.h"
#include <iostream>
#include <memory>
#include "Components/SpriteComponent.h"
#include "Components/TransformComponent.h"
using namespace sp;
int main()
{

	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("skylark.png");

	Entity skylarEntity;

	ComponentHandle<SpriteComponent> spriteHandle = skylarEntity.addNewComponent<SpriteComponent>();
	skylarEntity.addNewComponent<TransformComponent>();

	spriteHandle->sprite.setTexture(*texture, true);
	sf::Vector2u si = spriteHandle->sprite.getTexture()->getSize();

	spriteHandle->sprite.setOrigin(si.x / 2, si.y / 2);

	Game* mGame = new Game();
	mGame->entities.push_back(skylarEntity);
	mGame->initialize();
	mGame->mainLoop();
    return 0;
}

