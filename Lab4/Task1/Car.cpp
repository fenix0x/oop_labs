#include "stdafx.h"
#include <stdlib.h> 
#include "Car.h"

CCar::CCar()
:m_isEngineOn(false)
, m_gear(0)
, m_speed(0)
{
}

CCar::~CCar()
{
}

int GEAR_SPEED[5][2] = { { 0, 30 }, { 20, 50 }, { 30, 60 }, { 40, 90 }, { 50, 150 } };

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

bool CCar::IsSpeedInGearLimits(int gear, int speed)
{
	if (gear == 0)
	{
		return true;
	}
	if (gear == -1)
	{
		return ((speed >= -20) && (speed <= 0));
	}
	return ((speed >= GEAR_SPEED[gear - 1][0]) && (speed <= GEAR_SPEED[gear - 1][1]));
}

bool CCar::SetGear(int gear)
{
	if ((gear<-1) || (gear > 5))
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
	int real_speed = speed;
	if (m_gear < 0)
	{
		real_speed = -speed;
	}
	if ((m_gear == 0) && (speed > abs(m_speed)))
	{
		return false;
	}
	if (IsSpeedInGearLimits(m_gear, real_speed))
	{
		m_speed = real_speed;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::IsEngineOn()
{
	return m_isEngineOn;
}

int CCar::GetGear()
{
	return m_gear;
}

int CCar::GetSpeed()
{
	return abs(m_speed);
}

MoveDirection CCar::GetDirection()
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
