#include "Solution.h"
#include <bitset>
#include <iostream>

Solution::Solution()
	:mShape{nullptr}
{ }

Solution::Solution(Shape * shape)
	:mShape{ shape },
	 mGene{encodeShape(mShape)}
{ }

Solution::~Solution(){
	delete mShape;
}

Shape * Solution::shape() {
	return mShape;
}

void Solution::setShape(Shape * shape) {
	delete mShape;
	mShape = shape;
	mGene = encodeShape(mShape);
}

uint64_t Solution::encodeShape(Shape * shape) {
	uint64_t gene{ 0 };
	if (dynamic_cast<Circle*>(shape) != nullptr) {
		Circle * circle = static_cast<Circle*>(shape);
		int x = circle->point().x();
		int y = circle->point().y();
		int radius = circle->radius();
		/*std::cout << "\n--------------------------------------------------------";
		std::cout << "\ntests encodage: ";
		std::cout << "\nvaleur de x: " << x << " bits: " << std::bitset<32>(x);
		std::cout << "\nvaleur de y: " << y << " bits: " << std::bitset<32>(y);
		std::cout << "\nvaleur de radius: " << radius << " bits: " << std::bitset<32>(radius);*/
		gene |= x;
		//std::cout << "\ngene step 1: " << std::bitset<64>(gene);
		gene <<= 10;
		//std::cout << "\ngene step 2: " << std::bitset<64>(gene);
		gene |= y;
		//std::cout << "\ngene step 3: " << std::bitset<64>(gene);
		gene <<= 10;
		//std::cout << "\ngene step 4: " << std::bitset<64>(gene);
		gene |= radius;
		//std::cout << "\ngene step 5: " << std::bitset<64>(gene);
		//std::cout << "\n--------------------------------------------------------";
	}
	return gene;
}

Shape * Solution::decodeShape(uint64_t gene, Shape * shape) {
	if (dynamic_cast<Circle*>(shape) != nullptr) {
		int x{ 0 };
		int y{ 0 };
		int radius{ 0 };
		x |= gene;
		x >>= 20;
		gene <<= 44;
		gene >>= 44;
		y |= gene;
		y >>= 10;
		gene <<= 54;
		gene >>= 54;
		radius |= gene;
		Point2d point(x, y);
		Circle *circle = new Circle(point, radius);
		return circle;
	} else {
		return nullptr;
	}
}

uint64_t Solution::gene() {
	return mGene;
}

void Solution::setGene(int64_t gene, Shape * shape){
	mGene = gene;
	mShape = decodeShape(mGene, shape);
}

void Solution::calculateFitness(Obstacle & obstacle, parameters & currentParameters) {
	mFitness = mShape->fitnessRelevantValue(obstacle, currentParameters); //+ autres paramètres quand ils seront prêts
}

bool Solution::operator<(Solution const & solution) const {
	return mFitness < solution.mFitness;
}

void Solution::mutate(parameters currentParameters) {
	int probability = RandomTools::randomValue(0, 100);
	if (probability < currentParameters.oddsOfMutation) {
		if (dynamic_cast<Circle *>(mShape) != nullptr) {
			BitTools::flipBits(RandomTools::randomValue(0, 30), mGene);
			//std::cout << "\nmutating...";
		}
		//autres formes
	}
}

double Solution::fitness() {
	return mFitness;
}

//ébauche copy constructor
Solution::Solution(const Solution& source) 
	:mGene{source.mGene},
	 mFitness{source.mFitness}
{
	if (dynamic_cast<Circle*>(source.mShape) != nullptr) {
		Circle * sourceCircle = static_cast<Circle*>(source.mShape);
		mShape = new Circle();
		mShape->setCircle(sourceCircle->point(), sourceCircle->radius());
	}
	else {
		mShape = nullptr; //?
	}
}


//ébauche =overload
Solution & Solution::operator=(const Solution & source) {
	if (this == &source) {
		return *this;
	}
	delete mShape;
	mFitness = source.mFitness;
	mGene = source.mGene;
	if (dynamic_cast<Circle*>(source.mShape) != nullptr) {
		Circle * sourceCircle = static_cast<Circle*>(source.mShape);
		mShape = new Circle();
		mShape->setCircle(sourceCircle->point(), sourceCircle->radius());
	}
	else {
		mShape = nullptr; //?
	}
	return *this;
}