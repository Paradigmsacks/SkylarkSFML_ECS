#include "stdafx.h"
#include "Game.h"
#include "Components\SpriteComponent.h"
#include "Math\Vec2f.h"

namespace sp
{
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

	void Game::mainLoop()
	{
		sf::Clock mClock;
		mClock.restart();
		double accumulator = 0;
		double timestep = 1.0 / 30.0;
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
			render();
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
		sf::Vector2f movement;
		float speed = 200;

		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			//Update logic

			movement.x = 0;
			movement.y = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				movement.x = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				movement.x = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				movement.y = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				movement.y = 1;
			}

			movement.x *= speed * delta;
			movement.y *= speed * delta;

			it->getComponent<sp::SpriteComponent>()->sprite.move(movement);

		}
	}

	void Game::render()
	{
		sf::RenderStates states;
		mWindow->clear();

		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			//Render logic
			mWindow->draw(it->getComponent<sp::SpriteComponent>()->sprite, states);
		}



		mWindow->display();
	}
}
