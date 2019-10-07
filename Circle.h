#pragma once
#include "Shape.h"
#include <vector>



class Circle : public Shape
{
public:
	Circle(Point2d point, int radius);
	Circle();
	~Circle();
	Point2d point();
	int radius();
	void setPoint(Point2d point);
	void setRadius(int radius);
	double fitnessRelevantValue(Obstacle & obstacle, parameters & currentParameters) override;
	int isColliding(Obstacle & obstacle) override;
	int isOutOfBounds(parameters & currentParameters) override;
	void setCircle(Point2d point, int radius) override;

private:
	Point2d mPoint;
	int mRadius;
	const double pi = 3.14159265358979323846; //p-ê enlever, n'est plus nécessaire
};

