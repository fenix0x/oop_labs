#pragma once
#include <map>
#include <string>
#include <vector>
#include <fstream>

class CDictionary
{
public:
	CDictionary();
	CDictionary(std::string const& dictionaryPath);
	~CDictionary();
	void AddTranslation(std::string const& word2Traslate, std::string const& wordTranslated);
	std::string const& Translate(std::string const& word2Translate) const;
	bool HaveChanges() const;
	void SaveDictionary() const;

private:
	bool m_changed;
	const std::string m_dictionaryPath;
	std::map<std::string, std::string> m_dictionary;
	const std::string EMPTY_STRING = "";

	void ReadDictionary(std::string const& dictionaryPath);
};

