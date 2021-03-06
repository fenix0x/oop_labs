// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include "VectorProcessor.h"


using namespace std;

bool IsPositive(double value)
{
	return (value > 0);
}

void main()
{
	// ��������� ������ ����� �� stdin
	istream_iterator<double> start(cin);
	istream_iterator<double> end;
	
	vector<double> numbers(start, end);

	// ���������� ������ (������ ������� ������� ������ ���� ������� �� ����������� ������� ��������� �������)
	ProcessVector(numbers);

	ostream_iterator<double> output(cout, " ");

	/*
	cout << "processed vector: " << endl;
	// ������� ������ ����� ������ � stdout
	copy(numbers.begin(), numbers.end(), output);
	*/

	cout << endl << "sorted processed vector: " << endl;
	// ������� ������ ����� ������ � stdout � ��������������� ����
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), output);

}

