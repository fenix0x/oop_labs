#include "stdafx.h"
#define _USE_MATH_DEFINES 
#include <cmath>
#include "math.h"
#include <string>
#include <iostream>
using namespace std;

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0' ) || (*pLastChar != '\0' ));
	return param;
}

double DegreeToRadian(double degree)
{
	return degree * M_PI / 180;
}

double CalculateDistance(double velocity, double angle) 
{
	if (velocity < 0.0)
		return 0.0;
	else
		return pow(velocity, 2) * sin(2 * DegreeToRadian(angle)) / 9.8;
}

double EnterValue(const string message, bool & finish) 
{
	string value;
	const string ex = "exit";
	finish = false;
	double result = 0;
	bool err = false;
	do
	{
		cout << message;
		cin >> value;
		if (value == ex)
		{ 
			finish = true;
			return 0;
		}
		result = StringToDouble(value.c_str(), err);
		if (err)
		{
			cout << "You entered incorrect value" << endl;
		}
	} while (err);
	return result;
}

int main(int argc, char * argv[]) 
{
	/*
	printf("%g\n", CalculateDistance(3,30));
	printf("%g\n", CalculateDistance(3,45));
	printf("%g\n", CalculateDistance(3,90));
	printf("%g\n", CalculateDistance(3,60));
	printf("%g\n", CalculateDistance(-10,30));
	printf("%g\n", CalculateDistance(10,-30));
*/
	bool finish = false;
	bool err = false;

	do
	{
		double velocity = EnterValue("Enter initial velocity (or type 'exit') > ", finish);
		double angle;
		if (!finish)
		{
			angle = EnterValue("Enter initial angle (or type 'exit') > ", finish);
		}
		if (!finish)
		{
			cout << "Distance is: " << CalculateDistance(velocity, angle) << endl;
		}
	} while (!finish);

	cout << "Goodbye" << endl;
	return 0;
}

