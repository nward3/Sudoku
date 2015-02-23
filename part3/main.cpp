/* main.cpp
This is a simple driver that reads in the provided Sudoku
or Wordoku puzzle files using a Puzzle constructor and
then stores it in a vector of vectors before displaying
the unfinished puzzle to the screen */

#include<iostream>
#include "Sudoku.h"
using namespace std;

int main() {
	Puzzle<int> game;	// instantiate a puzzle of type int from the templated class
	game.play();		// play the sudoku game
	return 0;
}
