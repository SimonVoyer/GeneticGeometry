#include "Circle.h"
#include <iostream>

Circle::Circle(Point2d point, int radius){
	mPoint = point;
	mRadius = radius;
}

Circle::Circle() {
}

Circle::~Circle(){
}

Point2d Circle::point() {
	return mPoint;
}

int Circle::radius() {
	return mRadius;
}

void Circle::setPoint(Point2d point) {
	mPoint = point;
}

void Circle::setRadius(int radius) {
	mRadius = radius;
}

double Circle::fitnessRelevantValue(Obstacle & obstacle, parameters & currentParameters) {
	double fitnessValue = mRadius;
	int nbOfCollides = isColliding(obstacle);
	int crossover = isOutOfBounds(currentParameters);
	if (nbOfCollides > 0 || crossover > 0) {
		fitnessValue = 0;
	}
	return fitnessValue;
}

int Circle::isColliding(Obstacle & obstacle) {
	int nbOfCollides{ 0 };
	for (auto point : obstacle.obstacleVector() ) {
		if (mPoint.distance(point) <= mRadius) {
			nbOfCollides += 1;
		}
	}
	return nbOfCollides;
}

void Circle::setCircle(Point2d point, int radius) {
	mPoint = point;
	mRadius = radius;
}

int Circle::isOutOfBounds(parameters & currentParameters) {
	int x = mPoint.x();
	int y = mPoint.y();
	int crossover{ 0 };
	
	if (x - mRadius < 0) {
		crossover += std::abs(x - mRadius);
	}
	if (x + mRadius > currentParameters.layoutLength) {
		crossover += x + mRadius;
	}
	if (y - mRadius < 0) {
		crossover += std::abs(y - mRadius);
	}
	if (y + mRadius > currentParameters.layoutHeight) {
		crossover += y + mRadius;
	}

	return crossover;
}