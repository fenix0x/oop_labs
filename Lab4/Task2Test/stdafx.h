// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

///===============================
#define BOOST_TEST_MODULE Task1TestModule
#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702)	// отключаем предупреждение компилятора Visual Studio об unreachable code
#include <boost/test/unit_test.hpp>

///===============================

// TODO: reference additional headers your program requires here
