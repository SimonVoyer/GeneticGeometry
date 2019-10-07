#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Point2d.h"
#include "ConsoleColor.h"
#include <vector>

class Obstacle
{
public:
	Obstacle();
	void setSize(size_t size);
	void initializeVector(size_t size, int maxX, int maxY);
	std::vector<Point2d> & obstacleVector();
	size_t size();
	ConsoleColor color();
	void addObstacle(Point2d p);

private:
	
	std::vector<Point2d> mPointVector;
	ConsoleColor mColor;
};

#endif //OBSTACLE_H