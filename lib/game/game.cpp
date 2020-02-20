#include "include/game.h"
#include "include/gamestate.h"
#include "include/gameinfo.h"
#include "include/igamerenderer.h"
#include "include/key.h"
#include "include/rect.h"
#include "include/point.h"
#include "include/colour.h"
#include "include/size.h"

#include <vector>

namespace prpg {

//-----------------------------------------------------------------
template <typename T>
class DataGrid
{
public:
	DataGrid(int width, int height)
	: m_Size(width, height)
	{
		m_Data.resize(width * height, T());
	}
	
	//-----------------------------------------------------------------
	const T& getData(int x, int y) const
	{
		return m_Data.at(getIndex(x, y));
	}
	
	//-----------------------------------------------------------------
	void setData(int x, int y, const T& data)
	{
		m_Data[getIndex(x, y)] = data;
	}
	
	const Size& getSize() const { return m_Size; }
	
private:
	std::vector<T>	m_Data;
	Size			m_Size;
	
	//-----------------------------------------------------------------
	int getIndex(int x, int y) const
	{
		return (m_Size.width * y) + x;
	}
};

//-----------------------------------------------------------------
class Tile
{
public:
	Tile(const Colour& colour, bool blocks)
	: m_Colour(colour),
	m_Blocks(blocks)
	{}
	
	const Colour& getColour() const { return m_Colour; }
	bool getBlocks() const { return m_Blocks; }
	
private:
	Colour	m_Colour;
	bool	m_Blocks;
};
	
//-----------------------------------------------------------------
class TileInstance
{
public:
	TileInstance()
	: m_Tile(-1)
	{}
	
	TileInstance(const int tile)
	: m_Tile(tile)
	{}
	
	const int getTile() const { return m_Tile; }
	
private:
	int m_Tile;
};
	
//-----------------------------------------------------------------
class Area
{
public:
	Area(const std::vector<Tile>& tiles, const DataGrid<TileInstance>& geometry)
	: m_Tiles(tiles),
	m_Geometry(geometry)
	{}
	
	const std::vector<Tile>&		getTiles() const { return m_Tiles; }
	const DataGrid<TileInstance>&	getGeometry() const { return m_Geometry; }
	
private:
	std::vector<Tile> 		m_Tiles;
	DataGrid<TileInstance>	m_Geometry;
};

//-----------------------------------------------------------------
class AreaLoader
{
public:
	Area loadArea() const
	{
		std::vector<Tile> tiles {
			Tile(Colour{ 0, 0, 255 }, true),
			Tile(Colour{ 0, 255, 0 }, false)
		};
		
		Size s { 30, 30 };
		DataGrid<TileInstance> geometry(s.width, s.height);
		for (int x = 0; x < s.width; ++x)
		{
			for (int y = 0; y < s.height; ++y)
			{
				if (x > 4 && x < 12 && y > 5)
				{
					geometry.setData(x, y, TileInstance(1));
				}
				else
				{
					geometry.setData(x, y, TileInstance(0));
				}
			}
		}
		
		return Area(tiles, geometry);
	};
};
	
//-----------------------------------------------------------------
class Character
{
public:
	Character(const Point& pt)
	: m_Pt(pt)
	{}
	
	const Point& getPoint() const { return m_Pt; }
	void setPoint(const Point& pt) { m_Pt = pt; }
	
private:
	Point m_Pt;
};
	
//-----------------------------------------------------------------
Game::Game()
: m_Char(new Character(Point { 6, 6 }))
{}
	
//-----------------------------------------------------------------
Game::~Game()
{}

//-----------------------------------------------------------------
GameInfo Game::getGameInfo() const
{
	return {
		"prpg",
		Size { 800, 600 }
	};
}

//-----------------------------------------------------------------
GameState Game::getGameState() const
{
	return m_Running ? GameState::kRunning : GameState::kExit;
}

//-----------------------------------------------------------------
void Game::keyPressed(const Key& key)
{
	int a = 1;
	
	auto pt = m_Char->getPoint();
	
	switch (key)
	{
		case Key::kUp:
			pt.y -= a;
			break;
		case Key::kDown:
			pt.y += a;
			break;
		case Key::kLeft:
			pt.x -= a;
			break;
		case Key::kRight:
			pt.x += a;
			break;
		case Key::kEscape:
			m_Running = false;
			break;
	};
	
	AreaLoader areaLoader;
	const auto& area = areaLoader.loadArea();
	const auto& geom = area.getGeometry();
	const auto& tileInstance = geom.getData(pt.x, pt.y);
	if (!area.getTiles()[tileInstance.getTile()].getBlocks())
	{
		m_Char->setPoint(pt);
	}
}

//-----------------------------------------------------------------
void Game::update()
{
	
}

//-----------------------------------------------------------------
void Game::render(IGameRenderer& renderer)
{
	AreaLoader areaLoader;
	const auto& area = areaLoader.loadArea();
	
	// renderArea
	{
		const auto& geom = area.getGeometry();
		for (int x = 0; x < geom.getSize().width; ++x)
		{
			for (int y = 0; y < geom.getSize().height; ++y)
			{
				const auto& tileInstance = geom.getData(x, y);
	
				const Rect r { x * m_TileSize, y * m_TileSize, m_TileSize, m_TileSize };
				renderer.drawRect(r, area.getTiles()[tileInstance.getTile()].getColour());
			}
		}
	}
	
	const Rect r { m_Char->getPoint().x * m_TileSize, m_Char->getPoint().y * m_TileSize, m_TileSize, m_TileSize };
	const Colour c { 255, 100, 100 };
	renderer.drawRect(r, c);
	
	const Point p { 30, 30 };
	renderer.drawText(p, c, "Test");
}

}
