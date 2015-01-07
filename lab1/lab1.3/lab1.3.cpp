#include "stdafx.h"
#include "stdlib.h"

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0' ) || (*pLastChar != '\0' ));
	return param;
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates sum of its command line arguments.\n");
		return 0;
	}
	int sum = 0;
	for (int i = 1; i < argc; ++i)
	{
		bool err;
		int param = StringToInt(argv[i], err);
		if (err)
		{
			printf("Argument #%d is not a number.\n", i);
			return 1;
		}
		printf("%d", param);
		sum += param;
		if (i != argc-1)
		{
			printf(" + ");
		}
	}
	printf(" = %d", sum);
	return 0;
}

