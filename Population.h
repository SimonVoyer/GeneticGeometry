#ifndef POPULATION_H
#define POPULATION_H
#include "Solution.h"
#include <vector>

class Population
{
public:
	Population();
	~Population();
	std::vector<Solution> & solutionVector();
	void calculateFitness(Obstacle & obstacle, parameters & currentParameters);
	void addSolution(Solution solution);
	Solution value(size_t index);
	void setSize(size_t size);
	double & totalFitness();

private:
	std::vector<Solution> mSolutionVector;
	double mTotalFitness;
};
#endif //!POPULATION_H
