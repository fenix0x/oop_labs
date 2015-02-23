#include "stdafx.h"
#include "SolidBody.h"
#include <sstream>      // std::ostringstream

using namespace std;

CSolidBody::CSolidBody(double density)
: m_density(density)
{
	if (m_density <= 0)
	{
		throw invalid_argument("Incorrect density value");
	}
}

double CSolidBody::GetDensity() const
{
	return m_density;
}

double CSolidBody::GetMass() const
{
	return GetVolume() * m_density;
}

string CSolidBody::ToString() const
{
	std::ostringstream strm;
	strm << " Density: " << GetDensity() << " Weight: " << GetMass() << " Volume: " << GetVolume();
	return strm.str();
}
