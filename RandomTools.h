// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// File name :		RandomTools.h
// Author :			Jean-Christophe Demers
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Context :		AlgoGenetique
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Brief :			Programme de l'algorithme g�n�tique.
//
// Header de la classe d'outils pseudo-al�atoires
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef RANDOM_TOOLS_H
#define RANDOM_TOOLS_H


#include <random>
#include <vector>


class RandomTools
{
	static std::random_device sRandomDevice;
	static std::mt19937 sRandomGenerator;

public:
	static std::mt19937& generator() { return sRandomGenerator; }

	// Donne un nombre pseudo al�atoire entre 0 et (size - 1) correspondant � la taille du vecteur.
	static size_t randomIndex(const std::vector<double> & data);

	// Donne un nombre pseudo al�atoire entre 0 et (size - 1) donn�e (inclusivement).
	static size_t randomIndex(size_t size);

	// Donne un nombre pseudo al�atoire entre 0 et la valeur donn�e (inclusivement).
	static size_t randomValue(size_t value);

	// Donne un nombre pseudo al�atoire dans l'intervalle donn�.
	// Les bornes sont incluses.
	static int randomValue(int minValue, int maxValue);

	static size_t randomValue(size_t minValue, size_t maxValue);

	// Donne un nombre pseudo al�atoire dans l'intervalle donn�.
	// Les bornes sont incluses.
	static double randomValue(double minValue = 0.0, double maxValue = 1.0);

	// Met des nombres al�atoires dans un tableau selon l'intervalle donn�.
	// Les bornes sont incluses.
	static void randomize(std::vector<double> & data, double minValue = 0.0, double maxValue = 1.0);
};

#endif // RANDOM_TOOLS_H