#include "stdafx.h"
#include "../Task1/Cone.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <sstream>

using namespace std;

struct ConeTestsFixture
{
	CCone cone = CCone(2, 5, 3);
};

BOOST_FIXTURE_TEST_SUITE(ConeTests, ConeTestsFixture)

BOOST_AUTO_TEST_CASE(TestCone)
{
	BOOST_CHECK_EQUAL(cone.GetRadius(), 2);
	BOOST_CHECK_EQUAL(cone.GetHeight(), 5);
	BOOST_CHECK_EQUAL(cone.GetDensity(), 3);
	BOOST_CHECK_EQUAL(cone.GetVolume(), (1.0 / 3.0) * M_PI * 2 * 2);
	BOOST_CHECK_EQUAL(cone.GetMass(), cone.GetDensity() * cone.GetVolume());
}

BOOST_AUTO_TEST_SUITE_END();