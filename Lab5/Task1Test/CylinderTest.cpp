#include "stdafx.h"
#include "../Task1/Cylinder.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <sstream>

using namespace std;

struct CylinderTestsFixture
{
	CCylinder cylinder = CCylinder(2, 5, 3);
};

BOOST_FIXTURE_TEST_SUITE(CylinderTests, CylinderTestsFixture)

BOOST_AUTO_TEST_CASE(TestCylinder)
{
	BOOST_CHECK_EQUAL(cylinder.GetRadius(), 2);
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), 5);
	BOOST_CHECK_EQUAL(cylinder.GetDensity(), 3);
	BOOST_CHECK_EQUAL(cylinder.GetVolume(), (1.0 / 3.0) * M_PI * 2 * 2);
	BOOST_CHECK_EQUAL(cylinder.GetMass(), cylinder.GetDensity() * cylinder.GetVolume());
}

BOOST_AUTO_TEST_SUITE_END();