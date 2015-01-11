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

	bool IsEngineOn();

	int GetGear();

	int GetSpeed();

	MoveDirection GetDirection();

private:
	bool m_isEngineOn;
	int m_gear;
	int m_speed;

	bool IsSpeedInGearLimits(int gear, int speed);

};

