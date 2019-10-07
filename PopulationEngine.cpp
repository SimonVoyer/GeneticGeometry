
#include "PopulationEngine.h"
#include <iostream>
#include <bitset>

PopulationEngine::PopulationEngine()
	:mConverged{ false }
{ }

PopulationEngine::~PopulationEngine()
{ }

Population & PopulationEngine::parentPopulation()  {
	return mParentPopulation;
}

Population & PopulationEngine::childPopulation() {
	return mChildPopulation;
}

void PopulationEngine::setParentPopulation(Population parentPopulation){
	mParentPopulation = parentPopulation;
}

void PopulationEngine::setChildPopulation(Population childPopulation){
	mChildPopulation = childPopulation;
}

void PopulationEngine::calculateFitness() {
	mParentPopulation.calculateFitness(mObstacle, mCurrentParameters);
}

Solution PopulationEngine::selectParent()
{
	double percentChoice{ RandomTools::randomValue(0.0, 1.0) };
	double cumulativePercent{ 0.0 };
	//std::cout << "\npercentChoice= " << percentChoice;
	//std::cout << "\nTotalFitness= " << mParentPopulation.totalFitness();
	//std::cout << "\n--------------------------------";
	for (auto & solution : mParentPopulation.solutionVector()) {
		//std::cout << "\nSolutionFitness= " << solution.fitness();
		solution.calculateFitness(mObstacle, mCurrentParameters); //ajout pour test debug --> il semble y avoir bcp de junk dans le fitness à ce moment
		cumulativePercent += solution.fitness() / mParentPopulation.totalFitness();
		//std::cout << "\nCumulativePercent= " << cumulativePercent;
		if (percentChoice <= cumulativePercent) { //ici des fois il semble retourner un parent avec null, si valeur de percentChoice trop haute??? ******************************************
			return solution;
		}
	}
	return mParentPopulation.solutionVector().back();
	
}

Solution PopulationEngine::generateChild() {
	Solution parent1 = selectParent();
	Solution parent2 = selectParent();
	Solution child;
	int splicer;

	if (dynamic_cast<Circle*>(parent1.shape()) != nullptr) {
		splicer = RandomTools::randomValue(5,25);
	}
	child.setGene(BitTools::spliceMerge(BitTools::leftSplice(parent1.gene(), splicer), BitTools::rightSplice(parent2.gene(), splicer)), parent1.shape());
	child.calculateFitness(mObstacle, mCurrentParameters); //ajout test *****************
	//std::cout << "\nSplicer:" <<splicer;
	//std::cout << "\nParent1 genes:" << std::bitset<64>(parent1.gene());
	//std::cout << "\nParent2 genes:" << std::bitset<64>(parent2.gene());
	//std::cout << "\n  Child genes:" << std::bitset<64>(child.gene());
	//Circle * circle = static_cast<Circle*>(parent1.shape());
	//std::cout << "\nparent1: ";
	//std::cout << "\tcircle radius: " << circle->radius();
	//std::cout << "\tcircle x: " << circle->point().x();
	//std::cout << "\tcircle y: " << circle->point().y();
	//std::cout << "\tsolution fitness: " << parent1.fitness();
	//std::cout << "\n--------------------------: " << circle->radius();
	//circle = static_cast<Circle*>(parent2.shape());
	//std::cout << "\nparent2: ";
	//std::cout << "\tcircle radius: " << circle->radius();
	//std::cout << "\tcircle x: " << circle->point().x();
	//std::cout << "\tcircle y: " << circle->point().y();
	//std::cout << "\tsolution fitness: " << parent2.fitness();
	//std::cout << "\n--------------------------: " << circle->radius();
	//circle = static_cast<Circle*>(child.shape());
	//std::cout << "\nchild: ";
	//std::cout << "\ncircle radius: " << circle->radius();
	//std::cout << "\tcircle x: " << circle->point().x();
	//std::cout << "\tcircle y: " << circle->point().y();
	//child.calculateFitness();
	//std::cout << "\tsolution fitness: " << child.fitness();
	return child;
}

void PopulationEngine::newGeneration() {
	isConverging();
	calculateFitness();
	mChildPopulation.solutionVector().clear();
	std::cout << "\nAverage fitness of current gen: " << mParentPopulation.totalFitness()/mParentPopulation.solutionVector().size();
	for (int i{0}; i < mCurrentParameters.nbOfElites; ++i) {
		mChildPopulation.addSolution(mParentPopulation.solutionVector().at(i));
		//std::cout << "\nfitness  elite" << mChildPopulation.solutionVector().at(i).fitness();
	}
	for (int j{0}; j < (mCurrentParameters.populationSize - mCurrentParameters.nbOfElites); ++j) {
		Solution solution = generateChild();
		solution.mutate(mCurrentParameters);
		mChildPopulation.solutionVector().push_back(solution);
		//Circle * circle = static_cast<Circle*>(solution.shape());
		//std::cout << "\ncircle radius: " << circle->radius();
		//std::cout << "\tcircle x: " << circle->point().x();
		//std::cout << "\tcircle y: " << circle->point().y();
		//std::cout << "\tsolution fitness: " << solution.fitness();
	}
	mParentPopulation.solutionVector().swap(mChildPopulation.solutionVector());
	mCurrentParameters.currentIteration++;
}

void PopulationEngine::setObstacle(Obstacle & obstacle) {
	mObstacle = obstacle;
}

void PopulationEngine::setParameters(parameters & currentParameters) {
	mCurrentParameters = currentParameters;
}

bool PopulationEngine::isConverging() {
	if (mCurrentParameters.currentIteration >= mCurrentParameters.maxNbOfIterations) {
		mConverged = true;
		return true;
	}
	return false;
}

bool PopulationEngine::hasConverged() {
	return mConverged;
}



