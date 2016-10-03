#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "ECS\Entity.h"


typedef std::unique_ptr<sf::RenderWindow> RenderPTR;
class Game
{
public:
	Game();
	~Game();

	void initialize();
	void mainLoop(Entity* ent);
private:
	RenderPTR mWindow;
	sf::Event mEvent;
	void createWindow();
	void pollEvents();
	void update(double delta);
	void render(Entity* ent);
};

