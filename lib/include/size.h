#pragma once

namespace prpg {

//-----------------------------------------------------------------
struct Size
{
	Size(int width_, int height_)
	: width(width_),
	height(height_)
	{}
	
	int width = 0;
	int height = 0;
};

}
