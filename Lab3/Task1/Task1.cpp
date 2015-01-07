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
	// Считываем массив чисел из stdin
	istream_iterator<double> start(cin);
	istream_iterator<double> end;
	
	vector<double> numbers(start, end);

	// Обработать массив (Каждый элемент массива должен быть умножен на минимальный элемент исходного массива)
	ProcessVector(numbers);

	ostream_iterator<double> output(cout, " ");

	/*
	cout << "processed vector: " << endl;
	// Выводим массив через пробел в stdout
	copy(numbers.begin(), numbers.end(), output);
	*/

	cout << endl << "sorted processed vector: " << endl;
	// Выводим массив через пробел в stdout в отсортированном виде
	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), output);

}

