#pragma once

namespace prpg {

struct GameInfo;
class IGameRenderer;

enum class GameState;
enum class Key;
	
//-----------------------------------------------------------------
class Game
{
public:
	GameInfo getGameInfo() const;
	GameState getGameState() const;
	
	void keyPressed(const Key& key);
	void update();
	void render(IGameRenderer& renderer);
	
	int m_X = 0;
	int m_Y = 0;
	bool m_Running = true;
};

}
