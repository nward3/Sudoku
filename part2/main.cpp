/* main.cpp
This is a simple driver that reads in the provided Sudoku
or Wordoku puzzle files using a Puzzle constructor and
then stores it in a vector of vectors before displaying
the unfinished puzzle to the screen */

#include<iostream>
#include "Sudoku.h"
using namespace std;

int main() {
	cout << "The first object is of char type while the second object is of int type." << endl;
	Puzzle<char> game1;	// instantiate object of char type for Puzzle class
	Puzzle<int> game2;	// instantiate object of int type for Puzzle class

	cout << "Displaying game 1, the char puzzle: " << endl;
	game1.display();

	cout << "Displaying game 2, the int puzzle: " << endl;
	game2.display();
}
