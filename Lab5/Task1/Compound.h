#pragma once
#include "Body.h"
#include <vector>
#include <memory>


class CCompound :
	public CBody
{
public:
	CCompound();
	double GetDensity() const override;
	double GetVolume() const override;
	double GetMass() const override;
	std::string ToString() const override;

	bool Add(std::shared_ptr<CBody> part);

private:
	std::vector<std::shared_ptr<CBody>> m_parts;
	bool AlreadyHave(std::shared_ptr<CBody> body);
};

