#include "stdafx.h"
#include <vector>
#include <memory>
#include <sstream>
#include "Compound.h"

using namespace std;

CCompound::CCompound()
{
}

double CCompound::GetDensity() const
{
	return GetMass() / GetVolume();
}

double CCompound::GetVolume() const
{
	double volume = 0.0;
	for (auto body : m_parts)
	{
		volume += body->GetVolume();
	}
	return volume;
}

double CCompound::GetMass() const
{
	double mass = 0.0;
	for (auto body : m_parts)
	{
		mass += body->GetMass();
	}
	return mass;
}

std::string CCompound::ToString() const
{
	std::ostringstream strm;
	strm << "Compound." << " Density: " << GetDensity() << " Weight: " << GetMass() << " Volume: " << GetVolume();
	return strm.str();
}

bool CCompound::Add(std::shared_ptr<CBody> part)
{
	if (AlreadyHave(part))
	{
		return false;
	}
	m_parts.push_back(part);
	return true;
}

bool CCompound::AlreadyHave(std::shared_ptr<CBody> body)
{
	if (body.get() == this)
	{
		return true;
	}
	const CCompound * compound = dynamic_cast<const CCompound*>(body.get());
	if (compound != nullptr)
	{
		for (auto& obj : compound->m_parts)
		{
			bool answer = AlreadyHave(obj);
			if (answer)
			{
				return answer;
			}
		}
	}
	return false;
}