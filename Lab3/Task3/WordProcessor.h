#pragma once

#include "stdafx.h"
#include <string>
#include <map>

typedef std::map<std::string, int> WordsCountMapping;

WordsCountMapping CountWords(std::string const & inputText);