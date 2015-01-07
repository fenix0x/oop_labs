// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "PrimeNumbs.h"

using namespace std;

int const maxNumber = 1000000000;

void printUsage()
{
	cout << "USAGE: primes.exe max_number" << endl;
	cout << "       max_number - upper bound to find prime numbers" << endl;
	cout << "       max_number should be less then " << maxNumber << endl;
}

void main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printUsage();
		return;
	}

	int maxBound = atoi(argv[1]);
	if (maxBound > 100000000)
	{
		cout << "max_number is higher then " << maxNumber << endl << endl;
		printUsage();
		return;
	}

	cout << "processing...";

	set<int> primes = GeneratePrimeNumbersSet(maxBound);

	ostream_iterator<double> output(cout, " ");
	cout << endl << "Primes: ";
	copy(primes.begin(), primes.end(), output);
}

