#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

// calculates Fibonacci numbers

unsigned long StringToULong(const char * str, bool & err) 
{
	char * pLastChar = NULL;
	unsigned long param = strtoul(str, &pLastChar, 10);
	err = ((*str == '\0' ) || (*pLastChar != '\0' ));
	return param;
}

int main(int argc, char * argv[]) 
{
	if (argc < 2)
	{
		cout << "Usage: fib.exe N" << endl;
		cout << "	N - max Fibonacci number" << endl;
		return 0;
	}

	bool err;
	unsigned long n = StringToULong(argv[1], err);
	if (err) 
	{
		cout << "Argument is not a number." << endl;
		return 1;
	}
	if (n < 1) 
	{
		cout << "Argument should be greater then 0." << endl;
		return 1;
	}

	unsigned long prevValue = 0;
	unsigned long nextValue = 1;
	bool firstNumber = true;
	for (int i = 1; (nextValue < n) && (prevValue <= nextValue); ++i)
	{
		if (!firstNumber)
		{
			cout << ", ";
			if ((i % 5) == 1)
			{
				cout << endl;
				firstNumber = true;
			}
		}
		cout << nextValue;
		firstNumber = false;
		unsigned long tempValue = prevValue + nextValue;
		prevValue = nextValue;
		nextValue = tempValue;
	}

	return 0;
}
