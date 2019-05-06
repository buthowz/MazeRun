/*
 * Sujit Neupane
 * CSS 342 - Project4
 *
 * Cygwin
 *
 * ************
 * Reads maze from a file and store it in a char array
 */
#ifndef MAZE_H
#define MAZE_H
#include "position.h"
#include <string>
#include <vector>

using namespace std;

class Maze {
	private:
		int mazeHeight, mazeWidth;
		Position startingPosition;
		int endingIndex;
		char* mazeArray;
	public:
		//constructor
		Maze(string fileName);
		//destructor
		virtual ~Maze();
		//static constant variables
		static const char wall = '#', clear = ' ', path = '+', visited = '+';
		
		//reads file and loads the required data
		void readFile(string fileName);

		//gets maze height
		int getMazeHeight() const { return mazeHeight; }

		//gets maze width
		int getMazeWidth() const { return mazeWidth; }

		//gets starting position of the maze
		Position getStartingPosition() const { return startingPosition; }
		
		//gets exit index
		int getEndingIndex() const { return endingIndex; }

		//gets index of a character from the char array
		int getCharIndex(const Position& position) const;

		//sets the character in the char array
		void setMazeArrayChar(Position& p, char c);

		//gets character from the char array
		char getArrayChar(const Position& p) const;

		//prints out maze in console
		void createMaze(); 
};
#endif
