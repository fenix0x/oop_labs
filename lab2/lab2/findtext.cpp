#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int MAX_CHARS_PER_LINE = 512;

enum Err
{
	ERR_NO_ERROR,
	ERR_CANT_OPEN_FILE,
};


bool findLines(char* filename, char* textToSearch, Err & err)
{
	bool found = false;
	ifstream inputFile(filename);
	if (!inputFile)
	{
		cout << "File opening error" << endl;
		err = ERR_CANT_OPEN_FILE;
		return false;
	}
	int i = 0;
	// read each line of the file
	while (!inputFile.eof())
	{
		++i;
		string buf;
		getline(inputFile, buf);
		// find textToSearch in read line
		size_t foundTextPos = buf.find(textToSearch);
		if (foundTextPos != string::npos)
		{
			cout << i << endl;
			found = true;
		}
	}
	return found;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "USAGE: findtext.exe <file name> <text to search>" << endl;
		return 0;
	}
	char* filename = argv[1];
	char* textToSearch = argv[2];

	Err err = ERR_NO_ERROR;

	bool found = findLines(argv[1], argv[2], err);
	
	if (err == ERR_NO_ERROR)
	{
		if (!found)
		{
			cout << "Text not found." << endl;
		}
		return 0;
	}
	else
	{
		return err;
	}
}