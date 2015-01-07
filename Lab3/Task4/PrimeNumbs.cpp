#include "stdafx.h"
#include <set>
#include <vector>
#include "PrimeNumbs.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(int upperBound) {
	set<int> result;
	if (upperBound > 0)
	{
		vector<bool> prime(upperBound + 1, true);
		prime[0] = prime[1] = false;
		for (int i = 2; i*i <= upperBound; ++i)   // valid for n < 46340^2 = 2147395600
		if (prime[i]) 
		{
			for (int j = i*i; j <= upperBound; j += i)
			{
				prime[j] = false;
			}
		}
		for (int i = 2; i <= upperBound; ++i) 
		{
			if (prime[i])
			{
				result.insert(i);
			}
		}
	}
	return result;
}