#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "ECS\Entity.h"

namespace sp
{
	typedef std::unique_ptr<sf::RenderWindow> RenderPTR;
	class Game
	{
	public:
		Game();
		~Game();

		void initialize();
		void mainLoop();

		//Temporary
		std::vector<Entity> entities;

	private:
		RenderPTR mWindow;
		sf::Event mEvent;
		void createWindow();
		void pollEvents();
		void update(double delta);
		void render();

		
	};
}
