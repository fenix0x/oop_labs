#pragma once
#include "SolidBody.h"

class CCone :
	public CSolidBody
{

public:
	CCone(double radius, double height, double density);

	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	std::string ToString() const override;

private:
	double m_radius;
	double m_height;

};

