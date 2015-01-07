#pragma once

#include "stdafx.h"
#include <string>
#include <map>

using namespace std;

typedef std::map<string, int> WordsCountMapping;

WordsCountMapping CountWords(string const & inputText);