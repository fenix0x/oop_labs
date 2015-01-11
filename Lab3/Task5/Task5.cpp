// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ParseURL.h"

using namespace std;

void main()
{
	string inputText;
	while (getline(cin, inputText)) {
		Protocol protocol;
		int port;
		string host;
		string document;
		if (ParseURL(inputText, protocol, port, host, document))
		{
			cout << inputText << endl << "HOST: " << host << endl << "PORT: " << port << endl << "DOC:  " << document << endl;
		}
		else
		{
			cout << inputText << endl << "invalid URL" << endl;
		}
	}
}

