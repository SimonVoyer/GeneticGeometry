#include "PolygonShape.h"


// Constructeur 
PolygonShape::PolygonShape(double width, double height, Point2d center, double orientationDegrees)
	:mWidth{ width }, mHeight{ height }, mCenter{ center }, mOrientationDegrees{ orientationDegrees }
{
}

// Destructeur
PolygonShape::~PolygonShape()
{
}

// Les getters
///////////////

Polygon2d PolygonShape::polygon2d()
{
	return mPolygon2d;
}

double PolygonShape::width()
{
	return mWidth;
}

double PolygonShape::height()
{
	return mHeight;
}

Point2d PolygonShape::center()
{
	return mCenter;
}

double PolygonShape::orientationDegrees()
{
	return mOrientationDegrees;
}

// Les setters
//////////////

void PolygonShape::setPoly(Polygon2d Polygon2d)
{
	mPolygon2d = Polygon2d;
}

void PolygonShape::setWidth(double width)
{
	mWidth = width;
}

void PolygonShape::setHeight(double height)
{
	mHeight = height;
}

void PolygonShape::setOrientationDegrees(double orientationDegrees)
{
	mOrientationDegrees = orientationDegrees;
}

void PolygonShape::setCenter(Point2d center)
{
	mCenter = center;
}

void PolygonShape::draw(ConsoleImage & image, ConsoleColor const & segmentsColor)
{
	mPolygon2d.draw(image, segmentsColor);
}

// Méthodes publics (pour parent et enfants)
////////////////////////////////////////////

// Aire du PolygonShapee
double PolygonShape::fitnessRelevantValue(Obstacle & obstacle, parameters & currentParameters) {
	return mWidth * mHeight;
}

// Les appels implicites pour les enfants
/////////////////////////////////////////

// Pour le rectangle
void PolygonShape::buildRectangle()
{
	mPolygon2d.buildRectangle(mWidth, mHeight, mCenter, mOrientationDegrees);
}

// Pour le triangle
void PolygonShape::buildTriangle()
{

}
