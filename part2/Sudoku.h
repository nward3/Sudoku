/* Sudoku.h
This templated Puzzle class sets up the possibility
to create a traditional Sudoku or a Wordoku puzzle. */

#ifndef PUZZLE_H
#define PUZZLE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

template< typename T >
class Puzzle {

  public:
	Puzzle();	// class constructor
	void display();	// displays the unfinished puzzle to the screen	
  private:
	vector<vector <T> > puzzle;	// comprises the puzzle board
};

// class constructor
template< typename T>
Puzzle<T>::Puzzle() {
	// read in a file from the user
	string fileName;
	cout << "Please enter a file name: ";
	cin >> fileName;

	// update board to match specified puzzle
	T value;
	vector<T> tempvec;
	ifstream inFile;
	inFile.open (fileName.c_str());
	for (int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			inFile >> value;
			tempvec.push_back(value);
		}
		puzzle.push_back(tempvec);
		tempvec.clear();
	}
}

// displays the unfinished puzzle to the screen
template< typename T>
void Puzzle<T>::display(){
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cout << puzzle[i][j];
		}
		cout << endl;
	}
}
#endif
