// Task1Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include "../Task4/PrimeNumbs.h"

using namespace std;

bool VerifyPrimes(int maxBound, set<int> const& expectedSet)
{
	return (expectedSet == GeneratePrimeNumbersSet(maxBound));
}

// Набор тестов имеющих что-то общее
BOOST_AUTO_TEST_SUITE(PrimesTests)

// Единственный тест-кейс из набора тестов
BOOST_AUTO_TEST_CASE(Primes)
{
	set<int> expected;
	BOOST_CHECK(VerifyPrimes(0, expected));
	BOOST_CHECK(VerifyPrimes(1, expected));
	expected.insert(2);
	BOOST_CHECK(VerifyPrimes(2, expected));
	expected.insert(3);
	BOOST_CHECK(VerifyPrimes(3, expected));
	BOOST_CHECK(VerifyPrimes(4, expected));
	expected.insert(5);
	BOOST_CHECK(VerifyPrimes(5, expected));
	expected.insert(7);
	BOOST_CHECK(VerifyPrimes(10, expected));
}

BOOST_AUTO_TEST_SUITE_END()