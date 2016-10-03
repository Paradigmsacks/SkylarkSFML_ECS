#include "stdafx.h"
#include "Game.h"
#include "Components\SpriteComponent.h"
#include "Math\Vec2f.h"
#include "Components\TransformComponent.h"

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
		Vec2f movement;
		float speed = 400;

		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			//Update logic

			movement.X = 0;
			movement.Y = 0;
			float angleAdd = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				movement.Y = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				movement.Y = 1;
			}

			movement.X *= speed * delta;
			movement.Y *= speed * delta;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				angleAdd = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				angleAdd = 1;
			}

			angleAdd *= delta * 180;
			

			ComponentHandle<TransformComponent> trans = it->getComponent<TransformComponent>();
			trans->angle += angleAdd;

			sf::Vector2f tempVec = movement.toSFML();
			sf::Transform tempTrans;
			tempTrans.rotate(trans->angle);
			tempVec = tempTrans.transformPoint(tempVec);
			sp::Vec2f newVec(tempVec);

			trans->position.X += newVec.X;
			trans->position.Y += newVec.Y;

		}
	}

	void Game::render()
	{
		mWindow->clear();

		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			//Render logic
			sf::RenderStates states;

			Vec2f entityPos = it->getComponent<sp::TransformComponent>()->position;
			float angle = it->getComponent<sp::TransformComponent>()->angle;

			states.transform.translate(entityPos.X, entityPos.Y);
			states.transform.rotate(angle);

			mWindow->draw(it->getComponent<sp::SpriteComponent>()->sprite, states);
		}



		mWindow->display();
	}
}
