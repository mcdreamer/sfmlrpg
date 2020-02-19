#pragma once

#include "rect.h"
#include "colour.h"

namespace prpg {

//-----------------------------------------------------------------
class IGameRenderer
{
public:
	virtual ~IGameRenderer() {}
	
	virtual void drawRect(const Rect& rect, const Colour& colour)=0;
};

}
