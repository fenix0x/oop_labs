#include "stdafx.h"
#include <stdlib.h> 
//#include <boost/math/special_functions/sign.hpp>
#include "Car.h"

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

CCar::CCar()
:m_isEngineOn(false)
, m_gear(0)
, m_speed(0)
{
}

CCar::~CCar()
{
}

const int CCar::GEAR_SPEED[5][2] = { { 0, 30 }, { 20, 50 }, { 30, 60 }, { 40, 90 }, { 50, 150 } };

bool CCar::TurnOnEngine()
{
	if (!m_isEngineOn)
	{
		m_isEngineOn = true;
		m_gear = 0;
		m_speed = 0;
		return true;
	}
	else 
	{
		return false;
	}
}

bool CCar::TurnOffEngine()
{
	if ((m_isEngineOn) && (m_gear == 0) && (m_speed == 0))
	{
		m_isEngineOn = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::SetGear(int gear)
{
	if ((gear < -1) || (gear > 5))
	{
		return false;
	}
	if ((gear == 0) || (abs(m_gear - gear) < 2))
	{
		if (IsSpeedInGearLimits(gear, m_speed))
		{
			m_gear = gear;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool CCar::SetSpeed(int speed)
{
	if (speed < 0)
	{
		return false;
	}
	int realSpeed = speed;
	if (m_gear < 0)
	{
		realSpeed = -speed;
	}
	if ((m_gear == 0) && (speed > abs(m_speed)))
	{
		return false;
	}
	if ((IsSpeedInGearLimits(m_gear, realSpeed)) && ((sgn(realSpeed) == sgn(m_speed)) || (m_speed == 0) || (realSpeed == 0)))
	{
		m_speed = realSpeed;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::IsEngineOn() const
{
	return m_isEngineOn;
}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return abs(m_speed);
}

MoveDirection CCar::GetDirection() const
{
	if ((!m_isEngineOn) || (m_speed == 0))
	{
		return STOP;
	}
	if (m_gear < 0)
	{
		return REVERSE;
	}
	else
	{
		return FORWARD;
	}
}
