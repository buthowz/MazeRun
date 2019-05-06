/*
 * Point as a position
 * Created by Sujit Neupane
 * 11/10/2017
*/

#ifndef POSITION_H
#define POSITION_H
#include <iostream>

using namespace std;

class Position {
	public:
		Position();
		Position(const int x, const int y);
		Position(const Position& newPosition);
		virtual ~Position();
		Position& operator = (const Position & newPosition);
		int getX() const{
			return x;
		}
		int getY() const{
			return y;
		}
		void setX(const int x);
		void setY(const int y);
		
		//for its own output print
		friend  ostream & operator << (ostream & output, const Position& p);


	private:
		int x;
		int y;	
};
#endif
