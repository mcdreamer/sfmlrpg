#include "sfmlrenderer.h"

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
	s.setSize(sf::Vector2f(rect.width, rect.height));
	s.setPosition(rect.x, rect.y);
	s.setFillColor(convertColour(colour));
	
	m_Target.draw(s);
}
