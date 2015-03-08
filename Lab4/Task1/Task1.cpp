#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include "Car.h"

using namespace std;
using namespace boost;

string GetCarDirectionString(CCar const & car)
{
	switch (car.GetDirection()) {
	case (FORWARD) :
		return "Forward";
	case (STOP) :
		return "Stop";
	case(REVERSE) :
		return "Reverse";
	}
	return "Undefinied";
}

string GetCarEngineStatusString(CCar const & car)
{
	return car.IsEngineOn() ? "On" : "Off";
}

void GetCarInfo(const CCar & car)
// Выводит состояние двигателя автомобиля, направление движения, скорость и передачу
{
	cout << "Engine:    " << GetCarEngineStatusString(car) << endl;
	cout << "Direction: " << GetCarDirectionString(car) << endl;
	cout << "Gear:      " << car.GetGear() << endl;
	cout << "Speed:     " << car.GetSpeed();
	if (car.GetGear() < 0) {
		cout << " (R)";
	}
	cout << endl;
}

void PrintCommandHelp()
{
	cout << "Info - Вывести состояние двигателя автомобиля, направление движения, скорость и передачу." << endl;
	cout << "EngineOn - Включить двигатель." << endl;
	cout << "EngineOff - Выключить двигатель." << endl;
	cout << "SetGear <передача> - Включить заданную передачу." << endl;
	cout << "SetSpeed <скорость> - Установить заданную скорость." << endl;
	cout << "Exit - Выйти из программы." << endl;
	cout << "Help - Подсказка по коммандам." << endl;
}

void ProcessCommand(CCar & car, const string & inputCommand)
{
	if (inputCommand == "help")
	{
		PrintCommandHelp();
		return;
	}
	if (inputCommand == "info")
	{
		GetCarInfo(car);
		return;
	}
	if (inputCommand == "engineon")
	{
		car.TurnOnEngine();
		cout << "Engine " << GetCarEngineStatusString(car) << endl;
		return;
	}
	if (inputCommand == "engineoff")
	{
		car.TurnOffEngine();
		cout << "Engine " << GetCarEngineStatusString(car) << endl;
		return;
	}
	char_separator<char> sep(" ");
	tokenizer<char_separator<char>> tokens(inputCommand, sep);
	auto token = tokens.begin();
	if (*token == "setgear")
	{
		++token;
		try
		{
			if (car.SetGear(lexical_cast<int>(*token)))
			{
				cout << "Gear set to " << car.GetGear() << endl;
			}
			else
			{
				cout << "Can't change gear" << endl;
			}
		}
		catch (...)
		{
			cout << "undefinied value";
		}
		return;
	}
	if (*token == "setspeed")
	{
		++token;
		try
		{
			if (car.SetSpeed(lexical_cast<int>(*token)))
			{
				cout << "Speed set to " << car.GetSpeed() << endl;
			}
			else
			{
				cout << "Can't change speed" << endl;
			}
		}
		catch (...)
		{
			cout << "undefinied value";
		}
		return;
	}
	cout << "undefined command" << endl;
}

void main()
{
	SetConsoleOutputCP(1251);
	CCar car;
	string inputCommand;
	while (getline(cin, inputCommand)) {
		trim(inputCommand);
		to_lower(inputCommand);
		if (inputCommand == "exit")
		{
			break;
		}
		ProcessCommand(car, inputCommand);
	}
}