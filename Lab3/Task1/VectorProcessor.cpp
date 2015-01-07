#include "stdafx.h"
#include <algorithm>
#include <functional>
#include "VectorProcessor.h"
#include <numeric>

using namespace std;

void ProcessVector(std::vector<double> & numbers)
// Каждый элемент массива должен быть умножен на минимальный элемент исходного массива
{
	if (numbers.size() > 0)
	{
		auto minValue = *min_element(numbers.begin(), numbers.end());

		transform(numbers.begin(), numbers.end(),
			numbers.begin(), [minValue](double item){
			return item * minValue;
		});
	}
}