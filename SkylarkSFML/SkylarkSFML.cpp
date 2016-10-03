// SkylarkSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "ECS/Entity.h"
#include <iostream>
#include <memory>
#include "Components/SpriteComponent.h"
using namespace sp;
int main()
{

	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("skylark.png");

	Entity* skylarEntity = new Entity();

	ComponentHandle<SpriteComponent> spriteHandle = skylarEntity->addNewComponent<SpriteComponent>();
	spriteHandle->sprite.setTexture(*texture, true);

	Game* mGame = new Game();
	mGame->initialize();
	mGame->mainLoop(skylarEntity);
    return 0;
}

