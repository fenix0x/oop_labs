#include "stdafx.h"
#include "Parallelepiped.h"
#include <sstream>  

using namespace std;

CParallelepiped::CParallelepiped(double width, double height, double depth, double density)
: CSolidBody(density)
, m_width(width)
, m_height(height)
, m_depth(depth)
{
	if (m_width <= 0)
	{
		throw invalid_argument("Incorrect width value");
	}
	if (m_height <= 0)
	{
		throw invalid_argument("Incorrect height value");
	}
	if (m_depth <= 0)
	{
		throw invalid_argument("Incorrect depth value");
	}
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return m_width * m_height * m_depth;
}

string CParallelepiped::ToString() const
{
	std::ostringstream strm;
	strm << "Papallelepiped. Width: " << m_width << " Height: " << m_height << " Depth: " << m_depth << CSolidBody::ToString();
	return strm.str();
}
