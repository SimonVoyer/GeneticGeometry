#ifndef SHAPE_H
#define SHAPE_H

#include "Point2d.h"
#include "BitTools.h"
#include "Obstacle.h"
#include "Parameters.h"

class Shape
{
	//mettre fonctions communes, pas variables
private:

public:
	Shape();
	~Shape();
	virtual double fitnessRelevantValue(Obstacle & obstacle, parameters & currentParameters);
	virtual int isColliding(Obstacle & obstacle);
	virtual int isOutOfBounds(parameters & currentParameters);
	virtual void setCircle(Point2d point, int radius);
	//manque de virtuals???
};

#endif //!SHAPE_H