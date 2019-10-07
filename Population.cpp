#include "Population.h"

Population::Population()
	:mTotalFitness{0}
{}

Population::~Population() {
}

void Population::setSize(size_t size) {
	return mSolutionVector.resize(size);
}

double & Population::totalFitness() {
	return mTotalFitness;
}


std::vector<Solution> & Population::solutionVector() {
	return mSolutionVector;
}

void Population::calculateFitness(Obstacle & obstacle, parameters & currentParameters) {
	mTotalFitness = 0;
	for (auto solution : mSolutionVector) {
		solution.calculateFitness(obstacle, currentParameters);
		mTotalFitness += solution.fitness();
	}
	std::sort(mSolutionVector.rbegin(),mSolutionVector.rend());
}

void Population::addSolution(Solution solution) { //mettre &?
	mSolutionVector.push_back(solution);
}

Solution Population::value(size_t index) {
	return mSolutionVector.at(index);
}


