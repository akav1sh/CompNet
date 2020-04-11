#ifndef __UTILS_H
#define __UTILS_H

#pragma warning(disable: 4996)  //deprecation IO methods
#pragma warning(disable: 4326)  //main request int return instead of void

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int ENDLIST = -1;
// Enums declaration
enum ErrorType
{
	INVALID_INPUT_ERROR = 1,
	NO_SOLUTION_ERROR   = 2,
	EMPTY_STACK_ERROR   = 3
};

#endif // __UTILS_H