#include "stdafx.h"
#include "stdlib.h"

// calculates sum of the digits of i 

int StringToInt(const char * str, bool & err) 
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0' ) || (*pLastChar != '\0' ));
	return param;
}

int SumDigits(int i) {
	int sum = 0;
	// цикл продолжается до тех пор, пока число не станет равным 0  
	while (i != 0) 
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(int argc, char * argv[]) 
{
	int param = 1000;
	if (argc > 1)
	{
		bool err;
		param = StringToInt(argv[1], err);
		if (err) 
		{
			printf("Argument is not a number.\n");
			return 1;
		}
		if (param < 1) 
		{
			printf("Argument should be greater then 0.\n");
			return 2;
		}
	}

	bool firstNumber = true;
	for (int i = 1; i <= param; ++i) 
	{
		if (i % SumDigits(i) == 0)
			if (firstNumber) 
			{
				printf("%d", i);
				firstNumber = false;
			}
			else
			{
				printf(", %d", i);
			}
				
	}
	return 0;
}