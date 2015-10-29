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
	random_device randomDevice;
	default_random_engine defaultRandomEngine{ randomDevice() };

	uniform_int_distribution<int> dist{ low, high };

	return dist(defaultRandomEngine);
}
