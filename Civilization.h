#ifndef CIVILIZATION_H
#define CIVILIZATION_H
#include "PopulationEngine.h"

class Civilization
{
public:
	Civilization();
	~Civilization();
	std::vector<PopulationEngine> & populationEngineVector();
	void calculateFitness();
	void addPopulationEngine(PopulationEngine populationEngine);
	Obstacle & obstacle();
	void initializeObstacles(parameters & currentParameters);
	void propagateObstacles();
	void newGenerations();

private:
	std::vector<PopulationEngine> mPopulationEngineVector;
	Obstacle mObstacle;
};

#endif //!CIVILIZATION_H