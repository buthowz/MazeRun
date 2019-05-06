#include "position.h"

/*
 * Determines position based on X and Y 
 * @author Sujit Neupane
 * 11/13/2017
 */

Position::Position()
{
	x = 0;
	y = 0;
}

Position::Position(const int x, const int y): x(x), y(y)
{
}

Position::Position(const Position& newPosition) {
	x = newPosition.getX();
	y = newPosition.getY();
}

Position & Position::operator = (const Position& newPosition) {
	if (this == &newPosition) {
		return *this;
	}
	else{
		x = newPosition.getX();
		y = newPosition.getY();
		return *this;
	}	
}

Position::~Position() {
	x = 0;
	y = 0;	
}

void Position::setX(int x) {
	x = x;
}

void Position::setY(int y) {
	y = y;
}

ostream & operator << (ostream & output, const Position& p)
{
	output << "[" << p.x << "," << p.y << "]" << "->";
	return output;
}
