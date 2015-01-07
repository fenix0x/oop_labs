// Task1Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "../Task1/VectorProcessor.h"

using namespace std;

bool VerifyVectorProcessing(vector<double> inputNumbers, vector<double> const& expectedNumbers)
{
	ProcessVector(inputNumbers);
	return (inputNumbers == expectedNumbers);
}

// Набор тестов имеющих что-то общее
BOOST_AUTO_TEST_SUITE(VectorProcessingTests)

// Единственный тест-кейс из набора тестов
BOOST_AUTO_TEST_CASE(VectorProcessing)
{
	BOOST_CHECK(VerifyVectorProcessing({}, {}));
	BOOST_CHECK(VerifyVectorProcessing({ 5.0 }, { 25.0 }));
	BOOST_CHECK(VerifyVectorProcessing({ -5.0 }, { 25.0 }));
	BOOST_CHECK(VerifyVectorProcessing({ 2.0, 4.0 }, { 4.0, 8.0 }));
	BOOST_CHECK(VerifyVectorProcessing({0}, {0}));
	BOOST_CHECK(VerifyVectorProcessing({ 5, -5 }, {-25, 25}));
	BOOST_CHECK(VerifyVectorProcessing({ 1.5, 2 }, {2.25, 3}));
}

BOOST_AUTO_TEST_SUITE_END()