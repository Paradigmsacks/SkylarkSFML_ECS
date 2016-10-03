#include "stdafx.h"
#include "Game.h"
#include "Components\SpriteComponent.h"
#include "Types\Vec2.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::initialize()
{
	createWindow();
}

void Game::mainLoop(Entity* ent)
{
	sf::Clock mClock;
	mClock.restart();
	double accumulator = 0;
	float timestep = 1.0 / 30.0;
	double frametime = 0;

	while (mWindow->isOpen())
	{
		pollEvents();

		frametime = mClock.getElapsedTime().asSeconds();
		mClock.restart();
		if (frametime > timestep)
		{
			frametime = timestep;
		}
		accumulator += frametime;
		while (accumulator >= timestep)
		{
			update(timestep);
			accumulator -= timestep;


		}
		render(ent);
	}
}

void Game::createWindow()
{
	mWindow.reset(new sf::RenderWindow(sf::VideoMode(1600, 900), "SKYLARK", sf::Style::Default));

}

void Game::pollEvents()
{
	if (mWindow->pollEvent(mEvent))
	{
		if (mEvent.type == sf::Event::KeyPressed)
		{
			if (mEvent.key.code == sf::Keyboard::Escape)
			{
				mWindow->close();
			}		
		}
		if (mEvent.type == sf::Event::Closed)
		{
			mWindow->close();
		}
	}
}

void Game::update(double delta)
{

}

void Game::render(Entity* ent)
{
	sf::RenderStates states;
	states.transform.translate(100, 100);
	sf::CircleShape shape;
	mWindow->draw(ent->getComponent<Skylark::SpriteComponent>()->getSprite(), states);
	mWindow->display();
}
