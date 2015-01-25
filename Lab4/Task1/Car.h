#pragma once

enum MoveDirection
{
	FORWARD,
	REVERSE,
	STOP
};

class CCar
{
public:
	CCar();
	~CCar();

	bool TurnOnEngine();

	bool TurnOffEngine();

	bool SetGear(int gear);

	bool SetSpeed(int speed);

	bool IsEngineOn() const;

	int GetGear() const;

	int GetSpeed() const;

	MoveDirection GetDirection() const;

private:
	bool m_isEngineOn;
	int m_gear;
	int m_speed;

	static const int GEAR_SPEED[5][2];

	bool static IsSpeedInGearLimits(int gear, int speed)
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



};

