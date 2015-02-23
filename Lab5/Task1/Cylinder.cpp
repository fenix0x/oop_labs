#include "stdafx.h"
#include "Cylinder.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <sstream>      

using namespace std;

CCylinder::CCylinder(double radius, double height, double density)
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

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return M_PI * m_height * m_radius * m_radius;
}

string CCylinder::ToString() const
{
	std::ostringstream strm;
	strm << "Cylinder. Radius: " << m_radius << " Height: " << m_height << CSolidBody::ToString();
	return strm.str();
}

