#include "Obstacle.h"
#include "RandomTools.h"

Obstacle::Obstacle()
	:mColor(ConsoleColor::tW + ConsoleColor::bW)
{
}

void Obstacle::setSize(size_t size) {
	return mPointVector.resize(size);
}

std::vector<Point2d> & Obstacle::obstacleVector() {
	return mPointVector;
}
size_t Obstacle::size() {
	return mPointVector.size();
}
ConsoleColor Obstacle::color() {
	return mColor;
}

 void Obstacle::addObstacle(Point2d p) {
	return mPointVector.push_back(p);
}

void Obstacle::initializeVector(size_t size,  int maxX, int maxY) {
	mPointVector.resize(size);
	for (int i{ 0 }; i < size; ++i) {
		mPointVector.at(i) = Point2d(RandomTools::randomValue(0, maxX), RandomTools::randomValue(0, maxY));
	}
}
