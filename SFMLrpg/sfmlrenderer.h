#pragma once

#include <SFML/Graphics.hpp>

#include "include/igamerenderer.h"

//-----------------------------------------------------------------
class SFMLRenderer : public prpg::IGameRenderer
{
public:
	SFMLRenderer(sf::RenderTarget& target, const float displayScale)
	: m_Target(target), m_DisplayScale(displayScale)
	{}
	
	virtual void drawRect(const prpg::Rect& rect, const prpg::Colour& colour) override;
	virtual void drawText(const prpg::Point& pt, const prpg::Colour& colour, const std::string& text) override;
private:
	sf::RenderTarget&	m_Target;
	const float			m_DisplayScale;
};

