#ifndef POPULATION_ENGINE_H
#define POPULATION_ENGINE_H

#include "Population.h"
#include "Obstacle.h"
#include <vector>

class PopulationEngine
{
public:
	PopulationEngine();
	~PopulationEngine();
	Population & parentPopulation();
    Population & childPopulation();
	void setParentPopulation(Population parentPopulation);
	void setChildPopulation(Population childPopulation);
	void calculateFitness();
	Solution selectParent();
	Solution generateChild();
	void newGeneration();
	void setObstacle(Obstacle & obstacle);
	void setParameters(parameters & currentParameters);
	bool isConverging();
	bool hasConverged();

private:
	parameters mCurrentParameters;
	Population mParentPopulation;
	Population mChildPopulation;
	Obstacle mObstacle;
	bool mConverged;
};

#endif // !POPULATION_ENGINE_H

