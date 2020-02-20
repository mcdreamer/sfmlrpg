#include "sfmlrenderer.h"
#include "include/colour.h"
#include "include/rect.h"
#include "include/point.h"

namespace
{
	//-----------------------------------------------------------------
	sf::Color convertColour(const prpg::Colour& colour)
	{
		return sf::Color(colour.r, colour.g, colour.b);
	}
}

//-----------------------------------------------------------------
void SFMLRenderer::drawRect(const prpg::Rect& rect, const prpg::Colour& colour)
{
	sf::RectangleShape s;
	s.setSize(sf::Vector2f(rect.width * m_DisplayScale, rect.height * m_DisplayScale));
	s.setPosition(rect.x * m_DisplayScale, rect.y * m_DisplayScale);
	s.setFillColor(convertColour(colour));
	
	m_Target.draw(s);
}

//-----------------------------------------------------------------
void SFMLRenderer::drawText(const prpg::Point& pt, const prpg::Colour& colour, const std::string& text)
{
	sf::Font font;
	font.loadFromFile("/Users/adodman/mcdreamer/SFMLrpg/SFMLrpg/sansation.ttf");

	sf::Text t(text.c_str(), font);
	t.setPosition(pt.x * m_DisplayScale, pt.y * m_DisplayScale);
	t.setFillColor(convertColour(colour));
	t.setCharacterSize(24 * m_DisplayScale);
	
	m_Target.draw(t);;
}
