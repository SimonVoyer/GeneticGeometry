#include "Shape.h"

Shape::Shape(){
}

Shape::~Shape(){
}

double Shape::fitnessRelevantValue(Obstacle & obstacle, parameters & currentParameters){
	return 0.0;
}

int Shape::isColliding(Obstacle & obstacle) {
	return 0;
}

int Shape::isOutOfBounds(parameters & currentParameters) {
	return 0;
}

void Shape::setCircle(Point2d point, int radius){

}



