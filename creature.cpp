#include "creature.h"

/*
 * Creature moves up, left, down and right
 * author@ Sujit Neupane
 * 11/13/17
 */

//default constructor
Creature::Creature() {

}

//constructor with an argument of starting position for the creature to start moving
Creature::Creature(const Position& startingPosition): startingPosition(startingPosition), currentPosition(startingPosition) {

}

//destructor
Creature::~Creature() {
	
}

//moves up
void Creature::moveUp()
{
	currentPosition = Position(currentPosition.getX(), currentPosition.getY() - 1);
}

//moves left
void Creature::moveLeft()
{
	currentPosition = Position((currentPosition.getX() - 1), currentPosition.getY());

}


//moves down
void Creature::moveDown()
{
	currentPosition = Position((currentPosition.getX()), currentPosition.getY() + 1);

}

//moves right
void Creature::moveRight()
{	
	currentPosition = Position((currentPosition.getX() + 1), currentPosition.getY());
}

//sets current position
void Creature::setCurrentPosition(int x, int y) {
	Position p = Position(x, y);
	currentPosition = p;
}

