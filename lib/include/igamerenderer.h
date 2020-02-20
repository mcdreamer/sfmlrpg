#pragma once

#include <string>

namespace prpg {
	
struct Rect;
struct Point;
struct Colour;

//-----------------------------------------------------------------
class IGameRenderer
{
public:
	virtual ~IGameRenderer() {}
	
	virtual void drawRect(const Rect& rect, const Colour& colour)=0;
	virtual void drawText(const Point& pt, const Colour& colour, const std::string& text)=0;
};

}
