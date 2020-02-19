#pragma once

#include <SFML/Graphics.hpp>

namespace prpg {
class Game;
}

//-----------------------------------------------------------------
class SFMLRunner
{
public:
	void run();
	
private:
	void handleEvents(sf::RenderWindow& window, prpg::Game& game);
};
