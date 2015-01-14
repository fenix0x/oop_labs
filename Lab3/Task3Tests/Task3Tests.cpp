// Task1Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <map>
#include "../Task3/WordProcessor.h"

using namespace std;

bool VerifyWordsCount(string const& inputText, WordsCountMapping const& expectedMap)
{
	return (expectedMap == CountWords(inputText)); 
}

// Набор тестов имеющих что-то общее
BOOST_AUTO_TEST_SUITE(WordsCountingTests)

// Единственный тест-кейс из набора тестов
BOOST_AUTO_TEST_CASE(WordsCounting)
{
	WordsCountMapping expected;
	BOOST_CHECK(VerifyWordsCount("", expected));
	expected["one"] = 1;
	BOOST_CHECK(VerifyWordsCount("one", expected));
	expected["one"] = 2;
	BOOST_CHECK(VerifyWordsCount("one one", expected));
	BOOST_CHECK(VerifyWordsCount("one;one", expected));
	BOOST_CHECK(VerifyWordsCount("one\tone", expected));
	BOOST_CHECK(VerifyWordsCount("one\none", expected));
	expected["two"] = 1;
	BOOST_CHECK(VerifyWordsCount("one  one two", expected));
	BOOST_CHECK(VerifyWordsCount("onE  oNe , TWO", expected));
}

BOOST_AUTO_TEST_SUITE_END()