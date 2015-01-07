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

double evaluate(const double param1, const double param2, const OperatorEval exprOperator, ErrEval & err)
{
	switch (exprOperator)
	{
	case OPERATOR_SUM:
		return param1 + param2;
	case OPERATOR_SUBTR:
		return param1 - param2;
	case OPERATOR_MUL:
		return param1 * param2;
	case OPERATOR_DIV:
		if (param2 == 0)
		{
			err = ERR_DIV_BY_ZERO;
			return 0;
		}
		return param1 / param2;
	}
}

ErrEval processCommandStringEval(const int argc, char* argv[])
{
	double sum = 0.0;
	OperatorEval exprOperator = OPERATOR_SUM;
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
			double param = 0.0;
			param = StringToDouble(argv[i], err);
			if (err)
			{
				cout << "Argument #" << i << " is not a number." << endl;
				return ERR_NOT_NUMBER;
			}

			ErrEval errEv = ERR_NO_ERROR;

			sum = evaluate(sum, param, exprOperator, errEv);

			if (errEv == ERR_DIV_BY_ZERO)
			{
				cout << " " << param;
				cout << endl << "Division by zero" << endl;
				return ERR_DIV_BY_ZERO;
			}

			cout << " " << param;
		}
	}
	printf(" = %6.3f\n", sum);

	return ERR_NO_ERROR;
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

	return processCommandStringEval(argc, argv);
}

