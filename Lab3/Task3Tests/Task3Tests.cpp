// Task1Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <map>
#include "../Task3/WordProcessor.h"

using namespace std;

template <typename Map>
bool map_compare(Map const &lhs, Map const &rhs) {
	// No predicate needed because there is operator== for pairs already.
	return lhs.size() == rhs.size()
		&& std::equal(lhs.begin(), lhs.end(),
		rhs.begin());
}

bool VerifyWordsCount(string const& inputText, WordsCountMapping const& expectedMap)
{
	return map_compare(CountWords(inputText), expectedMap);
}


// ����� ������ ������� ���-�� �����
BOOST_AUTO_TEST_SUITE(WordsCountingTests)

// ������������ ����-���� �� ������ ������
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