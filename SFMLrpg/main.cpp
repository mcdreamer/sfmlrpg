#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"

namespace prpg
{
	//-----------------------------------------------------------------
	enum class Key
	{
		kUp,
		kDown,
		kLeft,
		kRight,
		kEscape
	};
	
	//-----------------------------------------------------------------
	struct Rect
	{
		int x = 0;
		int y = 0;
		int width = 0;
		int height = 0;
	};
	
	//-----------------------------------------------------------------
	struct Colour
	{
		int r = 0;
		int g = 0;
		int b = 0;
	};
	
	//-----------------------------------------------------------------
	class IGameRenderer
	{
	public:
		virtual ~IGameRenderer() {}
		
		virtual void drawRect(const Rect& rect, const Colour& colour)=0;
	};
	
	//-----------------------------------------------------------------
	struct GameInfo
	{
		std::string windowTitle;
	};
	
	//-----------------------------------------------------------------
	enum class GameState
	{
		kRunning,
		kExit
	};
	
	//-----------------------------------------------------------------
	class Game
	{
	public:
		GameInfo getGameInfo() const
		{
			return { "prpg" };
		}
		
		GameState getGameState() const
		{
			return m_Running ? GameState::kRunning : GameState::kExit;
		}
		
		void keyPressed(const Key& key)
		{
			int a = 10;
			
			switch (key)
			{
				case Key::kUp:
					m_Y -= a;
					break;
				case Key::kDown:
					m_Y += a;
					break;
				case Key::kLeft:
					m_X -= a;
					break;
				case Key::kRight:
					m_X += a;
					break;
				case Key::kEscape:
					m_Running = false;
					break;
			};
		}
		
		void update()
		{
			
		}
		
		void render(IGameRenderer& renderer)
		{
			Rect r { m_X, m_Y, 20, 20 };
			Colour c { 255, 100, 100 };
			renderer.drawRect(r, c);
		}
		
		int m_X = 0;
		int m_Y = 0;
		bool m_Running = true;
	};
}

namespace
{
	//-----------------------------------------------------------------
	class SFMLRenderer : public prpg::IGameRenderer
	{
	public:
		SFMLRenderer(sf::RenderTarget& target)
		: m_Target(target)
		{}
		
		virtual void drawRect(const prpg::Rect& rect, const prpg::Colour& colour) override
		{
			sf::RectangleShape s;
			s.setSize(sf::Vector2f(rect.width, rect.height));
			s.setPosition(rect.x, rect.y);
			s.setFillColor(sf::Color(colour.r, colour.g, colour.b));

			m_Target.draw(s);
		}
		
	private:
		sf::RenderTarget& m_Target;
	};
}

//-----------------------------------------------------------------
int main(int, char const**)
{
	prpg::Game g;
	const auto gameInfo = g.getGameInfo();

	sf::RenderWindow window(sf::VideoMode(800, 600), gameInfo.windowTitle);
	SFMLRenderer r(window);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
			if (event.type == sf::Event::KeyPressed) {
				
				switch (event.key.code)
				{
					case sf::Keyboard::Up:
						g.keyPressed(prpg::Key::kUp);
						break;
					case sf::Keyboard::Down:
						g.keyPressed(prpg::Key::kDown);
						break;
					case sf::Keyboard::Left:
						g.keyPressed(prpg::Key::kLeft);
						break;
					case sf::Keyboard::Right:
						g.keyPressed(prpg::Key::kRight);
						break;
					case sf::Keyboard::Escape:
						g.keyPressed(prpg::Key::kEscape);
						break;
					default:
						break;
				}
			}
		}
		
		window.clear();
		
		g.update();
		g.render(r);
		
		window.display();
		
		if (g.getGameState() == prpg::GameState::kExit)
		{
			window.close();
		}
	}

    return EXIT_SUCCESS;
}
