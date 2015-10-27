#include "stdafx.h"
#include "RandomInt.h"


RandomInt::RandomInt()
{
}


RandomInt::~RandomInt()
{
}

int RandomInt::generateInt(int low, int high)
{
	uniform_int_distribution<int> dist{ low, high };

	return dist(defaultRandomEngine);
}
