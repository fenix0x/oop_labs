#include "stdafx.h"
#include "Cone.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <sstream>      

using namespace std;

CCone::CCone(double radius, double height, double density)
: CSolidBody(density)
, m_radius(radius)
, m_height(height)
{
	if (m_radius <= 0)
	{
		throw invalid_argument("Incorrect radius value");
	}
	if (m_height <= 0)
	{
		throw invalid_argument("Incorrect height value");
	}
}

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return (1.0 / 3.0) * M_PI * m_height * m_radius * m_radius;
}

string CCone::ToString() const
{
	std::ostringstream strm;
	strm << "Cone. Radius: " << m_radius << " Height: " << m_height << CSolidBody::ToString();
	return strm.str();
}

