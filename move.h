#ifndef MOVE_H
#define MOVE_H
#include "maze.h"
#include "creature.h"

/*
 * Sujit Neupane
 * CSS 342 - Project4
 *
 * Cygwin
 *
 * ************
 * Moves a creature in a maze
 */


class Move {
	private: 
		Maze myMaze;
		Creature myCreature;
	public:
	//constructor
	Move(Maze& myMaze, Creature& myCreature);
	//destructor
	virtual ~Move();
	
	//moves up and recurse until the exit is found
	bool goUp(Maze& myMaze, Creature& myCreature);
	
	//moves left and recurse until the exit is found
	bool goLeft(Maze& mymaze, Creature& myCreature);
	
	//moves down and recurse
	bool goDown(Maze& mymaze, Creature& myCreature);

	//moves right and recurse until the exit is found
	bool goRight(Maze& mymaze, Creature& myCreature);
};
#endif

