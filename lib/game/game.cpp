#include "include/game.h"
#include "include/gamestate.h"
#include "include/gameinfo.h"
#include "include/igamerenderer.h"
#include "include/key.h"

namespace prpg {

//-----------------------------------------------------------------
GameInfo Game::getGameInfo() const
{
	return { "prpg" };
}

//-----------------------------------------------------------------
GameState Game::getGameState() const
{
	return m_Running ? GameState::kRunning : GameState::kExit;
}

//-----------------------------------------------------------------
void Game::keyPressed(const Key& key)
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

//-----------------------------------------------------------------
void Game::update()
{
	
}

//-----------------------------------------------------------------
void Game::render(IGameRenderer& renderer)
{
	Rect r { m_X, m_Y, 20, 20 };
	Colour c { 255, 100, 100 };
	renderer.drawRect(r, c);
}

}
