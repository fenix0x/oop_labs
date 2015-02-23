#pragma once
#include "SolidBody.h"

class CSphere :
	public CSolidBody
{

public:
	CSphere(double radius, double density);

	double GetRadius() const;
	double GetVolume() const override;
	std::string ToString() const override;

private:
	double m_radius;

};

