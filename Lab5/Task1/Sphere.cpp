#include "stdafx.h"
#include "Sphere.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <sstream>      

using namespace std;

CSphere::CSphere(double radius, double density)
: CSolidBody(density)
, m_radius(radius)
{
	if (m_radius <= 0)
	{
		throw invalid_argument("Incorrect radius value");
	}
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return (4.0 / 3.0) * M_PI * std::pow(m_radius, 3);
}

string CSphere::ToString() const
{
	std::ostringstream strm;
	strm << "Sphere. Radius: " << m_radius << CSolidBody::ToString();
	return strm.str();
}

