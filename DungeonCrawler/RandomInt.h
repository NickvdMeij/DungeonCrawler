#pragma once
#include <random>
using namespace std;
class RandomInt
{
private:
	random_device randomDevice;
	default_random_engine defaultRandomEngine{ randomDevice() };
public:
	RandomInt();
	~RandomInt();
	int generateInt(int low, int high);
};

