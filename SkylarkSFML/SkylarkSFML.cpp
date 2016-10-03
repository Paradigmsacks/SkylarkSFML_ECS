// SkylarkSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "ECS/Entity.h"
#include <iostream>
#include <memory>
#include "Components/SpriteComponent.h"
#include "Components/TransformComponent.h"

int main()
{

	Entity* spr = new Entity();

	spr->initialize();
	sf::Texture* texture = new sf::Texture();
	bool load = texture->loadFromFile("skylark.png");
	Skylark::SpriteComponent* sC = new Skylark::SpriteComponent();
	Skylark::TransformComponent* tC = new Skylark::TransformComponent();
	sC->setTexture(texture);
	spr->addComponent(sC);
	spr->addComponent(tC);
	Game* mGame = new Game();
	mGame->initialize();
	mGame->mainLoop(spr);
    return 0;
}

