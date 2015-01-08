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

double EnterValue(const string &message, bool & finish) 
{
	finish = false;
	double result = 0;
	bool err = false;
	do
	{
		string value;
		cout << message;
		cin >> value;
		if (value == "exit")
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
	bool finish = false;

	do
	{
		double velocity = EnterValue("Enter initial velocity (or type 'exit') > ", finish);
		double angle = -1;
		while ((!finish) && ((angle<0.0) || (angle>90.0)))
		{
			angle = EnterValue("Enter initial angle (0-90) (or type 'exit') > ", finish);
		}
		if (!finish)
		{
			cout << "Distance is: " << CalculateDistance(velocity, angle) << endl;
		}
	} while (!finish);

	cout << "Goodbye" << endl;
	return 0;
}

