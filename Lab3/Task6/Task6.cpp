// Task6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Dictionary.h"
#include <windows.h>

using namespace std;

bool ReadNewWord(string & newWord)
{
	cout << endl << "> ";
	getline(cin, newWord);
	return !newWord.empty();
}

bool TranslationFound(CDictionary const& dictionary, string const& word2Translate, string & translation)
{
	translation = dictionary.Translate(word2Translate);
	return !translation.empty();
}

void AskNewTranslation(CDictionary & dictionary, string const& word2Translate)
{
	cout << "Неизвестное слово \"" << word2Translate << "\". Введите перевод или пустую строку для отказа.";
	string translation;
	if (ReadNewWord(translation))
	{
		dictionary.AddTranslation(word2Translate, translation);
		cout << "Слово \"" << word2Translate << "\" сохранено в словаре как \"" << translation << "\".";
	}
	else
	{
		cout << "Cлово \"" << word2Translate << "\" проигнорировано.";
	}
}

void AskAndSaveChanges(CDictionary const& dictionary)
{
	if (dictionary.HaveChanges())
	{
		cout << "В словарь были внесены изменения.Введите Y или y для сохранения перед выходом." << endl;
		string answer;
		if (ReadNewWord(answer) && (answer == "Y" || answer == "y"))
			try
		{
			dictionary.SaveDictionary();
			cout << "Изменения сохранены. До свидания." << endl;
		}
		catch (exception e)
		{
			cout << e.what();
		}
	}
}

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string DICT_PATH = "dict.txt";
	CDictionary dictionary(DICT_PATH);

	string newWord;
	while (ReadNewWord(newWord) && (newWord != "..."))
	{
		string translation;
		if (TranslationFound(dictionary, newWord, translation))
		{
			cout << translation << endl;
		}
		else
		{
			AskNewTranslation(dictionary, newWord);
		}
	}

	AskAndSaveChanges(dictionary);
}

