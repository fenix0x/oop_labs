#pragma once
#include "Body.h"

class CSolidBody :
	public CBody
{

public:
	CSolidBody(double density);

	double GetMass() const override final;
	double GetDensity() const override final;
	std::string ToString() const override;

private:
	double m_density;

};

