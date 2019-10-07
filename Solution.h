#ifndef SOLUTION_H
#define SOLUTION_H

#include <cstdint>
#include "Shape.h"
#include "Circle.h"
#include "RandomTools.h"
#include "Parameters.h"

class Solution
{
public:
	Solution();
	Solution(Shape * shape);
	~Solution();
	uint64_t encodeShape(Shape * shape);
	Shape * decodeShape(uint64_t gene, Shape * shape);
	uint64_t gene();
	void setGene(int64_t gene, Shape * shape);
	Shape * shape();
	void setShape(Shape * shape);
	double fitness();
	void calculateFitness(Obstacle & obstacle, parameters & currentParameters);
	bool operator<(Solution const & solution) const;
	void mutate(parameters currentParameters);
	Solution & operator=(const Solution & source);   //vérifier
	Solution(const Solution& source);				 //vérifier

private:
	Shape * mShape;
	uint64_t mGene;
	double mFitness;
};

#endif //!SOLUTION_H