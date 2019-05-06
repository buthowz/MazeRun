#include "Move.h"
#include <iostream>

/*
 * Sujit Neupane
 * CSS 342 - Project4
 *
 * Cygwin
 *
 * ************
 * Moves a creature in a maze to Up, Left, Down and Right.
 */


//Constructor
Move::Move( Maze& myMaze, Creature& myCreature) : myMaze(myMaze), myCreature(myCreature) {
	//myMaze = myMaze;
	//myCreature = myCreature;
}

//Destructor
Move::~Move() {
}

//moves Up and recurse until the exit is found
bool Move::goUp(Maze& myMaze, Creature& myCreature) {

	int currentX = myCreature.getCurrentPosition().getX();
	int currentY = myCreature.getCurrentPosition().getY();
	int newY = currentY - 1;
	int height = myMaze.getMazeHeight();
	int width = myMaze.getMazeWidth();
	Position up = Position(currentX, newY);
	bool success;
	cout << myCreature.getCurrentPosition();

	//check if the new position is clear, inside the maze and not visited.
	if (myMaze.getArrayChar(up) != myMaze.wall && newY > 0 && myMaze.getArrayChar(up) != myMaze.visited) {
		if (myMaze.getArrayChar(up) != 'o') {
			myCreature.moveUp();
			myMaze.setMazeArrayChar(up, myMaze.path);//set to path

		}
		if (myMaze.getArrayChar(up) == 'o') {//at exit
			cout << up << " Exit Found!";
			success = true;
			return success;
		}	
		else {
			success = goUp(myMaze, myCreature);
			if (!success) {
				success = goLeft(myMaze, myCreature);
				if (!success) {
					success = goRight(myMaze, myCreature);
					if (!success) {
						myMaze.setMazeArrayChar(up, myMaze.visited);// set to visited
						myCreature.setCurrentPosition(currentX, newY + 1);// back track
						return success;
					}
				}
			}
		}
	}
	else {
		success = false;

	}
	
	
	return success;
}

//Moves Left and recurse until the exit is found
bool Move::goLeft(Maze& myMaze, Creature& myCreature) {

	int currentX = myCreature.getCurrentPosition().getX();
	int currentY = myCreature.getCurrentPosition().getY();
	int newX = currentX - 1;
	int height = myMaze.getMazeHeight();
	int width = myMaze.getMazeWidth();
	Position left = Position(newX, currentY);
	bool success;
	cout << myCreature.getCurrentPosition();

	//check if the new position is clear, inside the maze and not visited
	if (myMaze.getArrayChar(left) != myMaze.wall && newX > 0 && myMaze.getArrayChar(left) != myMaze.visited) {
		if (myMaze.getArrayChar(left) != 'o') {
			myCreature.moveLeft();
			myMaze.setMazeArrayChar(left, myMaze.path);//set to path

		}
		if(myMaze.getArrayChar(left) == 'o'){//at exit
			cout << left << " Exit Found!";

			success = true;
			return success;
		}
	
		else {
			success = goLeft(myMaze, myCreature);
			if (!success) {
				success = goDown(myMaze, myCreature);
				if (!success) {
					success = goUp(myMaze, myCreature);
					if (!success) {
						myMaze.setMazeArrayChar(left, myMaze.visited);// set to visited
						myCreature.setCurrentPosition(newX + 1, currentY);// back track
						return success;
					}
				}
			}
		}
	}
	else {
		success = false;
	}
	return success;
}

//Moves down and recurse until the exit is found
bool Move::goDown(Maze& myMaze, Creature& myCreature) {

	int currentX = myCreature.getCurrentPosition().getX();
	int currentY = myCreature.getCurrentPosition().getY();
	int newY;
	if (currentY < myMaze.getMazeHeight()) {
		newY = currentY + 1;

	} else {
		return false;
	}
	int height = myMaze.getMazeHeight();
	int width = myMaze.getMazeWidth();
	Position down;
	if (newY < myMaze.getMazeHeight()) {
		down = Position(currentX, newY);
	} else {
		return false;
	}
	bool success;
	cout << myCreature.getCurrentPosition();
	//down = myCreature.getCurrentPosition();
	//check if the new position is clear, inside the maze and not visited. **Not sure about newY <= or only <
	if (myMaze.getArrayChar(down) != myMaze.wall && newY < height && myMaze.getArrayChar(down) != myMaze.visited) {
		if (myMaze.getArrayChar(down) != 'o') {
			myCreature.moveDown();
			myMaze.setMazeArrayChar(down, myMaze.path);//set to path
		}
		if(myMaze.getArrayChar(down) == 'o'){//at exit
			cout << down << " Exit Found!" << endl; 
			success = true;
			return success;
		}
		else {
			cout << "DownLoop";
			success = goDown(myMaze, myCreature);
			cout << "Down Done";
			/*if (!success) {
				success = goLeft(myMaze, myCreature);
				if (!success) {
					success = goRight(myMaze, myCreature);
					if (!success) {
						myMaze.setMazeArrayChar(down, myMaze.visited);// set to visited
						myCreature.setCurrentPosition(currentX, newY - 1);// back track
						return success;
					}
				}
			}*/
		}
	}
	else {
		success = false;
	}
	return success;
}

//Moves right and recurse until the exit is found
bool Move::goRight(Maze& myMaze, Creature& myCreature) {

	int currentX = myCreature.getCurrentPosition().getX();
	int currentY = myCreature.getCurrentPosition().getY();
	int newX = currentX + 1;
	int height = myMaze.getMazeHeight();
	int width = myMaze.getMazeWidth();
	Position right = Position(newX, currentY);
	bool success;
	cout << myCreature.getCurrentPosition();

	//check if the new position is clear, inside the maze and not visited 
	if (myMaze.getArrayChar(right) != myMaze.wall && newX < width && myMaze.getArrayChar(right) != myMaze.visited) {
		if (myMaze.getArrayChar(right) != 'o') {
			myCreature.moveRight();
			myMaze.setMazeArrayChar(right, myMaze.path);//set to path
		}
		if(myMaze.getArrayChar(right) == 'o') {//at exit
			cout << right << " Exit Found!" << endl;
			success = true;
			return success;
		}
		else {
			success = goRight(myMaze, myCreature);
			if (!success) {
				success = goUp(myMaze, myCreature);
				if (!success) {
					success = goDown(myMaze, myCreature);
					if (!success) {
						myMaze.setMazeArrayChar(right, myMaze.visited);// set to visited
						myCreature.setCurrentPosition(newX -1 , currentY);// back track
						return success;
					}
				}
			}
		}
	}
	else {
		success = false;
	}
	return success;
}
