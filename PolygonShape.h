#ifndef _POLYGONSHAPE_H
#define _POLYGONSHAPE_H

#include "Polygon2d.h"
#include "Shape.h"
#include "Point2d.h"

class PolygonShape : public Shape
{
public:
	// Constructeur / destructeur
	PolygonShape(double width = 0, double height = 0, Point2d center = Point2d(0.0, 0.0), double orientationDegrees = 0.0);
	virtual ~PolygonShape();

	// Les getters
	Polygon2d polygon2d();
	double width();
	double height();
	Point2d center();
	double orientationDegrees();

	// les setters
	void setPoly(Polygon2d poly);
	void setWidth(double width);
	void setHeight(double height);
	void setOrientationDegrees(double orientationDegrees);
	void setCenter(Point2d center);
	void draw(ConsoleImage & image, ConsoleColor const & segmentsColor);

	// Méthodes publics
	double fitnessRelevantValue(Obstacle & obstacle, parameters & currentParameters);

protected:
	// Les attributs
	Polygon2d mPolygon2d;
	double mWidth;
	double mHeight;
	Point2d mCenter;
	double mOrientationDegrees;

	// Méthodes privées (appels implicites)
	void buildRectangle();
	void buildTriangle();
};

#endif //_POLYGONSHAPE_H


