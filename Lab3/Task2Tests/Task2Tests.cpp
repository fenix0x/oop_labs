// Task1Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "../Task2/RemoveExtraSpaces.h"

using namespace std;

bool VerifyStringProcessing(string inputString, string const& expectedString)
{
	RemoveExtraSpaces(inputString);
	return (expectedString.compare(RemoveExtraSpaces(inputString)) == 0);
}

// Набор тестов имеющих что-то общее
BOOST_AUTO_TEST_SUITE(StringProcessingTests)

// Единственный тест-кейс из набора тестов
BOOST_AUTO_TEST_CASE(StringProcessing)
{
	BOOST_CHECK(VerifyStringProcessing("", ""));
	BOOST_CHECK(VerifyStringProcessing("  ", ""));
	BOOST_CHECK(VerifyStringProcessing("A", "A"));
	BOOST_CHECK(VerifyStringProcessing("   A", "A"));
	BOOST_CHECK(VerifyStringProcessing("A   ", "A"));
	BOOST_CHECK(VerifyStringProcessing("   A   ", "A"));
	BOOST_CHECK(VerifyStringProcessing("   Abcd    efd", "Abcd efd"));
	BOOST_CHECK(VerifyStringProcessing("   Abcd    efd    ", "Abcd efd"));
}

BOOST_AUTO_TEST_SUITE_END()