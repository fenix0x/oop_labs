// Task1Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "../Task2/RemoveExtraSpaces.h"
#include <boost/test/unit_test.hpp>

bool VerifyStringProcessing(std::string inputString, std::string const& expectedString)
{
	RemoveExtraSpaces(inputString);
	return (expectedString == RemoveExtraSpaces(inputString));
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