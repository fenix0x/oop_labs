#include "stdafx.h"
#include <vector>
#include <set>
#include "PrimeNumbs.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> result;
	if (upperBound > 0)
	{
		vector<bool> prime(upperBound + 1, true);
		prime[0] = prime[1] = false;
		for (int i = 2; i * i <= upperBound; ++i)   // valid for n < 46340^2 = 2147395600
		{
			if (prime[i])
			{
				int idx = i;
				for (int j = 2; j <= upperBound / i; ++j)
				{
					idx += i;
					if (prime[idx]) prime[idx] = false;
				}
			}
		}
		for (int i = 2; i <= upperBound; ++i)
		{
			if (prime[i])
			{
				result.insert(result.end(), i);
			}
		}
	}
	return result;
}