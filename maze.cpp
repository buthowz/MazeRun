
/*
 * Sujit Neupane
 * CSS 342 - Project4
 *
 * Cygwin
 *
 * ************
 * Reads maze from a file and store it in a char 2D array
 */

#include "maze.h"
#include <fstream>
#include <sstream>
#include <iostream>

//Constructor
Maze::Maze(string fileName) {
	readFile(fileName);
}

//destructor
Maze::~Maze() {
	delete[] mazeArray;//it is causing "aborted (core dump)" error, not sure why.
}

//Reads file and assigns data
void Maze::readFile(string fileName) {
	ifstream infile;
	infile.open(fileName);
	if (infile.is_open()) {
		string numberLine;
		char character;
		int heightNum, widthNum, startX, startY;
		getline(infile, numberLine);//gets the first line only
		istringstream myStream(numberLine);

		//process first line only for height, width, and starting point
		while (myStream >> heightNum >> widthNum >> startX >> startY) { 
			cout << "Maze Height: " << heightNum << endl;
			cout << "Maze Width: " << widthNum << endl;
			cout << "Maze Start X: " << startX << endl;
			cout << "Maze Start Y: " <<startY << endl;
			mazeHeight = heightNum;	
			mazeWidth = widthNum;
			Position start = Position(startX, startY);
			startingPosition = start;
		}
		mazeArray = new char[mazeHeight * mazeWidth];//creates maze array based on the read height and width of the maze
		string line;
		int index = 0; //for index of char array
		int row = 0; //for row bounding
		
		//process rest of the lines from the file
		while (!infile.eof() && row < mazeHeight) {
			row++; //increases here so that it does not go further beyond given row of maze
			getline(infile, line);
			for (int i = 0; i < mazeWidth; i++) {
				char ch = line.at(i);
				if (ch == 'o') {
					endingIndex = index; //saves ending point as a index
				}
				mazeArray[index] = ch;
				index++;
			}
		
		}
		//handles if there is no proper start point
		if (getArrayChar(startingPosition) != clear) {
			cout << "Bad maze, No Start!" << endl;
			exit(-1);
		}
		//handles mazeSizeBig, means the size is big but not enough data to fill it
		if (row < mazeHeight && infile.eof()) {
			cout << "Bad maze, Na data!" << endl;	
		}

	}
	else {
		cout << "Could not open the file!" << endl;
		exit(-1);
	}
	infile.close();
		
}

//Gets character index from array based on the position provided   
int Maze::getCharIndex(const Position& position) const {
	int x = position.getX();
	int y = position.getY();
	return x + mazeWidth * y;
}

//sets character in the maze array provided position and character to set
void Maze::setMazeArrayChar(Position& p, char c) {
	int index = getCharIndex(p);
	mazeArray[index] = c;
}

//gets the character from the array provided position
char Maze::getArrayChar(const Position& position) const {
	int index = getCharIndex(position);
	return mazeArray[index];
}

//prints out mazearray items
void Maze::createMaze() {
	for (int i = 1; i <= mazeHeight * mazeWidth; i++) {
		cout << mazeArray[i-1];
		if (i % mazeWidth == 0) {
			cout << "\n"; //new line at the end of each row for maze appearance
		}
	}
} 
