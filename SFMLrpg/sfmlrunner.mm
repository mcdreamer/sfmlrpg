#include "sfmlrunner.h"
#include "sfmlrenderer.h"

#include <optional>

#include "include/game.h"
#include "include/key.h"
#include "include/colour.h"
#include "include/gameinfo.h"
#include "include/gamestate.h"
#include "include/igamerenderer.h"

namespace
{
	//-----------------------------------------------------------------
	std::optional<prpg::Key> convertKeyCode(const sf::Keyboard::Key& key)
	{
		switch (key)
		{
			case sf::Keyboard::Up:
				return prpg::Key::kUp;
			case sf::Keyboard::Down:
				return prpg::Key::kDown;
			case sf::Keyboard::Left:
				return prpg::Key::kLeft;
			case sf::Keyboard::Right:
				return prpg::Key::kRight;
			case sf::Keyboard::Escape:
				return prpg::Key::kEscape;
			default:
				return {};
		}
	};
}

//-----------------------------------------------------------------
void SFMLRunner::run()
{
	prpg::Game game;
	const auto gameInfo = game.getGameInfo();
	
	sf::RenderWindow window(sf::VideoMode(800, 600), gameInfo.windowTitle);
	SFMLRenderer r(window);
	
	while (window.isOpen())
	{
		handleEvents(window, game);
		
		window.clear();
		
		game.update();
		game.render(r);
		
		window.display();
		
		if (game.getGameState() == prpg::GameState::kExit)
		{
			window.close();
		}
	}
}

//-----------------------------------------------------------------
void SFMLRunner::handleEvents(sf::RenderWindow& window, prpg::Game& game)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		
		if (event.type == sf::Event::KeyPressed)
		{
			const auto keyCode = convertKeyCode(event.key.code);
			if (keyCode)
			{
				game.keyPressed(*keyCode);
			}
		}
	}
}
