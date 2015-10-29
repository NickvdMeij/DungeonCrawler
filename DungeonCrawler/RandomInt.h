#pragma once
#include <random>
using namespace std;
class RandomInt
{
private:
public:
	RandomInt();
	~RandomInt();
	static int generateInt(int low, int high);
};

