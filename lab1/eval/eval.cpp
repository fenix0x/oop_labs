#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

enum ErrEval
{
	ERR_NO_ERROR,
	ERR_EVEN_ARGUMENTS,
	ERR_NOT_OPERATOR,
	ERR_NOT_NUMBER,
	ERR_DIV_BY_ZERO,
};

enum OperatorEval
{
	OPERATOR_SUM,
	OPERATOR_SUBTR,
	OPERATOR_MUL,
	OPERATOR_DIV,
	OPERATOR_UNDEF,
};

const OperatorEval GetOperator(const char * str)
{
	if (*str == '+')
		return OPERATOR_SUM;
	if (*str == '-')
		return OPERATOR_SUBTR;
	if (*str == '*')
		return OPERATOR_MUL;
	if (*str == '/')
		return OPERATOR_DIV;

	return OPERATOR_UNDEF;
}

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0' ) || (*pLastChar != '\0' ));
	return param;
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		cout << "Program calculates expression of command line arguments." << endl;
		return 0;
	}
	if ((argc % 2) == 1) 
	{
		cout << "Program accept only odd number of command line arguments." << endl;
		return ERR_EVEN_ARGUMENTS;
	}
	double sum = 0.0;
	OperatorEval exprOperator = OPERATOR_SUM;
	double param = 0.0;
	for (int i = 1; i < argc; ++i)
	{
		bool err;
		if ((i % 2) == 0) 
		{
			exprOperator = GetOperator(argv[i]);
			if (exprOperator == OPERATOR_UNDEF) {
				cout << "Argument #" << i << " should be + - * or /." << endl;
				return ERR_NOT_OPERATOR;
			}
			cout << " " << argv[i];
		} 
		else
		{
			param = StringToDouble(argv[i], err);
			if (err)
			{
				cout << "Argument #" << i << " is not a number." << endl;
				return ERR_NOT_NUMBER;
			}
			switch (exprOperator)
			{
			case OPERATOR_SUM: 
				sum = sum + param;
				break;
			case OPERATOR_SUBTR: 
				sum = sum - param;
				break;
			case OPERATOR_MUL: 
				sum = sum * param;
				break;
			case OPERATOR_DIV: 
				if (param == 0)
				{
					cout << " " << param;
					cout << endl << "Division by zero" << endl;
					return ERR_DIV_BY_ZERO;
				}
				sum = sum / param;
				break;
			}
			cout << " " << param;
		}

	}
	printf(" = %6.3f\n", sum);
	return 0;
}

