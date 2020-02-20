#pragma once

#include <memory>

namespace prpg {

struct GameInfo;
class IGameRenderer;

enum class GameState;
enum class Key;
	
class Character;
	
//-----------------------------------------------------------------
class Game
{
public:
	Game();
	~Game();
	
	GameInfo getGameInfo() const;
	GameState getGameState() const;
	
	void keyPressed(const Key& key);
	void update();
	void render(IGameRenderer& renderer);
	
	bool m_Running = true;
	
	static const int m_TileSize = 16;
	
	std::unique_ptr<Character>	m_Char;
};

}
