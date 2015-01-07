// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "WordProcessor.h"

using namespace std;


void main()
{
	string inputText;
	string tempStr;

	while (std::getline(cin, tempStr)) {
		inputText += "\n";
		inputText += tempStr;
	}

	WordsCountMapping wordCountsMap = CountWords(inputText);

	for (WordsCountMapping::const_iterator it = wordCountsMap.begin();
		it != wordCountsMap.end();
		++it)
	{
		cout << it->first << ": " << it->second << "\n";
	}

}

