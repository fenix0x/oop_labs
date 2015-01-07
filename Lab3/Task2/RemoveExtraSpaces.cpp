#include "stdafx.h"
#include <locale> 

using namespace std;

std::string RemoveExtraSpaces(std::string const& arg)
{
	bool isSymbolsStarted = false;
	bool haveSpaces = false;
	string result = "";
	for (unsigned i = 0; i < arg.size(); ++i)
	{
		const char ch = arg[i];
		if (isspace(ch)) 
		{
			haveSpaces = true;
		}
		else
		{
			if (isSymbolsStarted && haveSpaces)
				result += " ";
			result += ch;
			isSymbolsStarted = true;
			haveSpaces = false;
		}
	}
	return result;
}