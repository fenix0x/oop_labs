#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include "WordProcessor.h"

using namespace std;
using namespace boost;

WordsCountMapping CountWords(string const & inputText)
{
	WordsCountMapping result;
	char_separator<char> sep(" ,;\t\n");
	tokenizer<char_separator<char>> tokens(inputText, sep);
	for (const auto& token : tokens) 
	{
		++result[to_lower_copy(token)];
	}
	return result;
}