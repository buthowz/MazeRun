/*
 * creature with its starting position
 * author@ Sujit Neupane
 * 11/10/2017
 */
#ifndef CREATURE_H
#define CREATURE_H
#include "position.h"

class Creature {
	private:
		Position startingPosition;
		Position currentPosition;
	public:
		Creature();
		Creature(const Position& startingPosition);//currentPosition and startingPosition are same in the beginning
		virtual ~Creature();
		void moveUp();
		void moveLeft();
		void moveDown();
		void moveRight();
		Position& getStartingPosition() { return startingPosition; }
		Position& getCurrentPosition() { return currentPosition;  }
		void setCurrentPosition(int x, int y);
};
#endif
