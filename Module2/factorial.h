#pragma once

#include "defs.h"

#ifdef USE_INT_TYPE_FOR_FACTORIAL
	#define TYPE_FOR_FACTORIAL int
#else
	#define TYPE_FOR_FACTORIAL float
#endif

TYPE_FOR_FACTORIAL factorial(TYPE_FOR_FACTORIAL n);