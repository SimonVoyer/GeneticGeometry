#ifndef RECTANGLE2D_H
#define RECTANGLE2D_H

#include "Rectangle2d.h"
#include "PolygonShape.h"

class Rectangle2d :public PolygonShape {

public:
	Rectangle2d(double width, double height, Point2d center = Point2d(0.0, 0.0), double orientationDegrees = 0.0);
	~Rectangle2d();
};







#endif //!RECTANGLE_H