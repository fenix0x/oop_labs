// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "RemoveExtraSpaces.h"

using namespace std;

void main()
{
	string inputString;
	getline(cin, inputString);
	cout << RemoveExtraSpaces(inputString);
}


