#include "stdafx.h"
#include "../Task1/Sphere.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <sstream>

using namespace std;

struct SphereTestsFixture
{
	CSphere sphere = CSphere(2, 3);
};

BOOST_FIXTURE_TEST_SUITE(SphereTests, SphereTestsFixture)

BOOST_AUTO_TEST_CASE(TestSphere)
{
	BOOST_CHECK_EQUAL(sphere.GetRadius(), 2);
	BOOST_CHECK_EQUAL(sphere.GetDensity(), 3);
	BOOST_CHECK_EQUAL(sphere.GetVolume(), (4.0 / 3.0) * M_PI * pow(2, 3));
	BOOST_CHECK_EQUAL(sphere.GetMass(), sphere.GetDensity() * sphere.GetVolume());
}

BOOST_AUTO_TEST_SUITE_END();