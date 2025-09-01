#include "factorial.h"

TYPE_FOR_FACTORIAL factorial(TYPE_FOR_FACTORIAL n)
{
	TYPE_FOR_FACTORIAL result = 1;
	for (int i = 1; i <= n; ++i) 
	{
		result *= i;
	}

	return result;
}