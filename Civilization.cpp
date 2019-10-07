#include "Civilization.h"

Civilization::Civilization()
{
}

Civilization::~Civilization()
{
}

std::vector<PopulationEngine>& Civilization::populationEngineVector() {
	return mPopulationEngineVector;
}

void Civilization::calculateFitness()
{
	for (auto populationEngine : mPopulationEngineVector) {
		populationEngine.calculateFitness();
	}
}

void Civilization::addPopulationEngine(PopulationEngine populationEngine){
	mPopulationEngineVector.push_back(populationEngine);
}


Obstacle & Civilization::obstacle() {
	return mObstacle;
}

void Civilization::initializeObstacles(parameters & currentParameters) {
	mObstacle.initializeVector(currentParameters.nbOfObstacles, currentParameters.layoutLength, currentParameters.layoutHeight);
	propagateObstacles();
}

void Civilization::propagateObstacles() {
	for (auto & populationEngine : mPopulationEngineVector) {
		populationEngine.setObstacle(mObstacle);
	}
}

void Civilization::newGenerations() {
	for (auto & populationEngine : mPopulationEngineVector) {
		if (!populationEngine.hasConverged()) {
			populationEngine.newGeneration();
		}
	}
}


