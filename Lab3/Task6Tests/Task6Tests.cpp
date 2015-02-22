#include "stdafx.h"
#include "../Task6/Dictionary.h"
#include <string>
#include <boost/filesystem.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(EmptyDictionary)

BOOST_AUTO_TEST_CASE(CheckAddToDictionary)
{
	CDictionary dictionary;
	BOOST_CHECK(dictionary.Translate("heart").empty());
	dictionary.AddTranslation("heart", "сердце");
	BOOST_CHECK(dictionary.HaveChanges());
	BOOST_CHECK(dictionary.Translate("heart") == "сердце");
}

BOOST_AUTO_TEST_CASE(CheckUpperKeyTranslate)
{
	CDictionary dictionary;
	dictionary.AddTranslation("heart", "сердце");
	BOOST_CHECK(dictionary.Translate("Heart") == "сердце");
	BOOST_CHECK(dictionary.Translate("heArt") == "сердце");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(FileDictionary)

std::string DICT_PATH = "dict.txt";

BOOST_AUTO_TEST_CASE(CheckFileDictionary)
{
	CDictionary dictionary(DICT_PATH);
	BOOST_CHECK(!dictionary.Translate("heart").empty());
	BOOST_CHECK(!dictionary.HaveChanges());
	BOOST_CHECK(dictionary.Translate("heart") == "сердце");
	BOOST_CHECK(dictionary.Translate("HOmE") == "дом");
}

BOOST_AUTO_TEST_CASE(CheckSaveFileDictionary)
{
	string temp = DICT_PATH + ".tmp";
	boost::filesystem::copy_file(DICT_PATH, temp, boost::filesystem::copy_option::overwrite_if_exists);
	CDictionary dictionary(temp);
	dictionary.AddTranslation("peace", "мир");
	dictionary.SaveDictionary();
	CDictionary newdictionary(temp);
	BOOST_CHECK(dictionary.Translate("peace") == "мир");
}

BOOST_AUTO_TEST_SUITE_END()