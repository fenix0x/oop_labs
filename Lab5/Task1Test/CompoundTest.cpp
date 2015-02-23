#include "stdafx.h"
#include "../Task1/Compound.h"
#include "../Task1/Cone.h"
#include "../Task1/Parallelepiped.h"
#include <memory>

using namespace std;

struct CompoundFixture
{
	CCompound compound;
};

BOOST_FIXTURE_TEST_SUITE(CompoundTests, CompoundFixture)

BOOST_AUTO_TEST_CASE(CompoundTest)
{
	shared_ptr<CBody> cone = make_shared<CCone>(5, 6, 1);
	shared_ptr<CBody> box = make_shared<CParallelepiped>(1, 2, 3, 4);
	BOOST_CHECK(compound.Add(cone));
	BOOST_CHECK(compound.Add(box));
	BOOST_CHECK(!compound.Add(make_shared<CCompound>(compound)));
}

BOOST_AUTO_TEST_SUITE_END()