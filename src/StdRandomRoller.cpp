#include <dicenotation/roller/StdRandomRoller.h>

#include <chrono>
#include <random>

StdRandomRoller::StdRandomRoller()
{
}


StdRandomRoller::~StdRandomRoller()
{
}

int StdRandomRoller::roll(int numberOfFaces)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine engine(seed);
	std::uniform_int_distribution<int> distribution(1, numberOfFaces);
	return distribution(engine);
}

void StdRandomRoller::seed()
{
}

void StdRandomRoller::seed(int seed)
{
}