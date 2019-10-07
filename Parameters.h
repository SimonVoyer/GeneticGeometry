#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <string>
struct parameters
{
	int layoutHeight;
	int layoutLength;
	int nbOfObstacles;
	int oddsOfMutation;
	int nbOfElites;
	int populationSize;
	int nbOfPopulations;
	int currentIteration;
	int maxNbOfIterations;
	std::string color1;
	std::string color2;
	std::string color3;
	std::string color4;
};
#endif // !PARAMETERS_H
