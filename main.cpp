#include "move.h"
#include <string>
#include <iostream>

/*
 * Sujit Neupane
 * CSS 342 - Project4
 *
 * Cygwin
 *
 * ************
 * Main to move creature by creating a maze read from file
 */


using namespace std;

int main(int argc, char** argv) {
	if (argc > 1) {
		string fileName = argv[1];
		Maze myMaze = Maze(fileName);
		cout << endl;
		cout << "Moves: " << endl;
		Position startPosition = myMaze.getStartingPosition();
		Creature myCreature = Creature(startPosition);
		Move myMove = Move(myMaze, myCreature);
	 	
		/*bool success = myMove.goUp(myMaze, myCreature);
		if (!success) {	
			success = myMove.goLeft(myMaze, myCreature);
		}
		if (!success) {
			success = myMove.goDown(myMaze, myCreature);
		}
		if (!success) {
			success = myMove.goRight(myMaze, myCreature);
		}
		//if no exit
		if (!success) {
			cout << "No exit - Sarte was right!" << endl;
		}*/
		
		cout << "\nFinal Maze: " << endl;
		myMaze.createMaze();
	}
	else {
		cout << "Did not open the file!" << endl;
		exit(-1);
	}	
	return 0;	
}
