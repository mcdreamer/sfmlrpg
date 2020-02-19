#pragma once

#include <SFML/Graphics.hpp>

#include "include/igamerenderer.h"

//-----------------------------------------------------------------
class SFMLRenderer : public prpg::IGameRenderer
{
public:
	SFMLRenderer(sf::RenderTarget& target)
	: m_Target(target)
	{}
	
	virtual void drawRect(const prpg::Rect& rect, const prpg::Colour& colour) override;
	
private:
	sf::RenderTarget& m_Target;
};

