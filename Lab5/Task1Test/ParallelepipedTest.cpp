#include "stdafx.h"
#include "../Task1/Parallelepiped.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <sstream>

using namespace std;

struct ParallelepipedTestsFixture
{
	CParallelepiped box = CParallelepiped(2, 3, 4, 2);
};

BOOST_FIXTURE_TEST_SUITE(ParallelepipedTests, ParallelepipedTestsFixture)

BOOST_AUTO_TEST_CASE(TestParallelepiped)
{
	BOOST_CHECK_EQUAL(box.GetWidth(), 2);
	BOOST_CHECK_EQUAL(box.GetHeight(), 3);
	BOOST_CHECK_EQUAL(box.GetDepth(), 4);
	BOOST_CHECK_EQUAL(box.GetDensity(), 2);
	BOOST_CHECK_EQUAL(box.GetVolume(), 2 * 3 * 4);
	BOOST_CHECK_EQUAL(box.GetMass(), 2 * 3 * 4 *2);
}

BOOST_AUTO_TEST_SUITE_END();