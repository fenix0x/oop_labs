// Task1Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Task1/Car.h"

struct JustCreatedCarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(JustCreatedCar, JustCreatedCarFixture)

BOOST_AUTO_TEST_CASE(IsStoped)
{
	BOOST_CHECK(!car.IsEngineOn());
}

BOOST_AUTO_TEST_CASE(IsAtGear0)
{
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
}

BOOST_AUTO_TEST_CASE(IsAtSpeed0)
{
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
}

BOOST_AUTO_TEST_CASE(BeingTurnedOnIsTurnedOnAtSpeed0Gear0)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.IsEngineOn());
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK(!car.TurnOnEngine());
}

BOOST_AUTO_TEST_SUITE_END()

struct TurnedOnCarFixture
{
	CCar car;
	TurnedOnCarFixture()
	{
		car.TurnOnEngine();
	}
};

BOOST_FIXTURE_TEST_SUITE(TurnedOnTVSet, TurnedOnCarFixture)

BOOST_AUTO_TEST_CASE(CheckGearShifting)
{
	BOOST_CHECK_EQUAL(car.GetDirection(), STOP);
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.IsEngineOn());
	BOOST_CHECK_EQUAL(car.GetGear(), 1);
	BOOST_CHECK_EQUAL(car.GetDirection(), STOP);
	BOOST_CHECK(!car.SetGear(2));
	BOOST_CHECK(car.SetSpeed(25));
	BOOST_CHECK(!car.SetSpeed(55));
	BOOST_CHECK_EQUAL(car.GetDirection(), FORWARD);
	BOOST_CHECK(car.SetGear(2));
	BOOST_CHECK_EQUAL(car.GetGear(), 2);
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(!car.SetSpeed(30));
	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(!car.SetGear(1));
}

BOOST_AUTO_TEST_SUITE_END()

