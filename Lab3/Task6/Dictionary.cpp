#include "stdafx.h"
#include "Dictionary.h"
#include <boost\algorithm\string.hpp>
#include <clocale>

using namespace std;

CDictionary::CDictionary()
: m_changed(false)
{
}

CDictionary::CDictionary(std::string const& dictionaryPath)
: m_changed(false)
, m_dictionaryPath(dictionaryPath)
{
	ReadDictionary(dictionaryPath);
}


CDictionary::~CDictionary()
{
}

void CDictionary::AddTranslation(std::string const& word2Traslate, std::string const& wordTranslated)
{
	string key = boost::to_lower_copy(word2Traslate);
	if (m_dictionary.find(key) == m_dictionary.end())
	{
		m_dictionary[key] = wordTranslated;
		m_changed = true;
	}
}


std::string const& CDictionary::Translate(std::string const& word2Translate)const
{
	auto entity = m_dictionary.find(boost::to_lower_copy(word2Translate));
	if (entity != m_dictionary.end())
	{
		return entity->second;
	} else
	{
		return EMPTY_STRING;
	}
}

bool CDictionary::HaveChanges() const
{
	return m_changed;
}

void CDictionary::SaveDictionary()const
{
	if (!m_dictionaryPath.empty())
	{
		setlocale(LC_ALL, "Russian");
		string tempFile = m_dictionaryPath + ".tmp";

		ofstream output(tempFile);
		if (output.is_open()) {
			for (auto iterator : m_dictionary) {
				output << iterator.first << " " << iterator.second << endl;
			}
			output.close();
			if (remove(m_dictionaryPath.c_str()) == 0)
			{
				if (rename(tempFile.c_str(), m_dictionaryPath.c_str()) != 0)
				{
					throw std::invalid_argument("can't update dictionary: " + tempFile);
				}
			}
			else
			{
				throw std::invalid_argument("can't update dictionary: " + tempFile);
			}
		}
		else
		{
			throw std::invalid_argument("can't save temp dictionary: " + tempFile);
		}

	}
}

void CDictionary::ReadDictionary(std::string const& dictionaryPath)
{
	if (!dictionaryPath.empty()) 
	{
		setlocale(LC_ALL, "Russian");
		ifstream input(dictionaryPath);
		if (!input.bad())
		{
			string key, translation;
			while (input >> key >> translation)
			{
				m_dictionary[key] = translation;
			}
		}
		else
			throw std::invalid_argument("can't read dictionary: " + dictionaryPath);
	}
}

