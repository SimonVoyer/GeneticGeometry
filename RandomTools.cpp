// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// File name :		RandomTools.cpp
// Author :			Jean-Christophe Demers
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Brief :			Programme de l'algorithme génétique
//
// Code de la classe d'outils pseudo-aléatoires
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include "RandomTools.h"


#include <algorithm>


std::random_device RandomTools::sRandomDevice;
std::mt19937 RandomTools::sRandomGenerator{ sRandomDevice() };


size_t RandomTools::randomIndex(const std::vector<double> & data)
{
	return randomIndex(data.size());
}

size_t RandomTools::randomIndex(size_t size)
{
	return randomValue(size - 1);
}

size_t RandomTools::randomValue(size_t value)
{
	std::uniform_int_distribution<size_t> uniformDistribution(0, value);
	return uniformDistribution(sRandomGenerator);
}

int RandomTools::randomValue(int minValue, int maxValue)
{
	std::uniform_int_distribution<> uniformDistribution(minValue, maxValue);
	return uniformDistribution(sRandomGenerator);
}

size_t RandomTools::randomValue(size_t minValue, size_t maxValue)
{
	std::uniform_int_distribution<> uniformDistribution(minValue, maxValue);
	return uniformDistribution(sRandomGenerator);
}

double RandomTools::randomValue(double minValue, double maxValue)
{
	std::uniform_real_distribution<> uniformDistribution(minValue, maxValue);
	return uniformDistribution(sRandomGenerator);
}

void RandomTools::randomize(std::vector<double> & data, double minValue, double maxValue)
{
	std::generate(data.begin(), data.end(),
		[minValue, maxValue]() -> double { return randomValue(minValue, maxValue); });
}
