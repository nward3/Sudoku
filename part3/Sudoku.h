/* Sudoku.h
This templated Puzzle class sets up the possibility
to create a traditional Sudoku or a Wordoku puzzle.
This particular iteration of the class is for part 3
of lab5, which focuses on Sudoku. */

#ifndef PUZZLE_H
#define PUZZLE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

template< typename T >
class Puzzle {
  public:
	Puzzle();			// class constructor
	void display();			// displays the puzzle to the screen	
	void change(int, int);		// changes the number in a certain location of the grid
	int isComplete();		// checks if the puzzle is complete (filled) yet
	int isValid(int, int, int);	// checks if the specified location is valid
	int isEmpty(int, int);		// checks if the space in the grid is empty
	void play();			// allows the user to attempt to complete the puzzle
  private:
	vector<vector <T> > puzzle;	// comprises the puzzle board
};

// class constructor
template< typename T>
Puzzle<T>::Puzzle() {
	// read in a file from the user
	string fileName;	// string for the name of the specified file
	cout << "Please enter a file name: ";
	cin >> fileName;

	// update board to match specified puzzle
	T value;		// value (char/int/etc) to be placed into grid
	vector<T> tempvec;	// temp vector to create space in memory and place values into grid
	ifstream inFile;	// specify the input file stream use to establish the c style string
	inFile.open (fileName.c_str());

	// loop through the 9x9 puzzle grid
	for (int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			inFile >> value;
			tempvec.push_back(value);	// ensure memory avaiable & place the value
		}
		puzzle.push_back(tempvec);		// update the puzzle's grid based on the temp vector
		tempvec.clear();			// clear the temp vector's values for next iteration
	}
}

// displays the puzzle to the screen
template< typename T>
void Puzzle<T>::display() {
	// loops through the 9x9 grid
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			// output the value at the specified spot & separate values with a space
			cout << puzzle[i][j] << " ";
		}
		cout << endl;	// display the next row of the puzzle grid on a new line
	}
}

// changes the number of a certain spot on the grid
template< typename T>
void Puzzle<T>::change(int newrow, int newcol) {
	int row=newrow;		// row position to be updated
	int col=newcol;		// column position to be updated
	int selection;		// replacement number in the puzzle
	int truth=0;		// 1 if isValid is true, 0 otherwise
	char newlocat='n';	// 1 if user wants to change specified location; 0 otherwise

	// loops until a valid number is specified or until the user opts to select a different spot
	while ((truth==0)&&(newlocat=='n')) {
		cout << "Specify a new number: ";
		cin >> selection;
		truth=isValid(row, col, selection);

		// the specified number is not a valid input
		if (truth==0) {
			cout << "Invalid move or location. Try again." << endl;
			// in the event the user to wants to change location or cannot place a value
			cout << "Do you want to try a new location? (y/n): ";
			cin >> newlocat;
		}
	}

	// update the puzzle grid to reflect change; If new location specified this does not need to happen
	if (newlocat=='n') {
		puzzle[row][col]=selection;
	}
}

// determine if choice is a valid input for the grid
template< typename T>
int Puzzle<T>::isValid(int newrow, int newcol, int newnumber) {
	int valid=1;		// 1 if selection is valid; 0 otherwise
	int row=newrow;		// row specified
	int col=newcol;		// column specified
	int number=newnumber;	// number to input if the location is valid
	int a,b;		// loop counters for the 3x3 grids

	// checks that the specified number is a valid number between 1 and 9 (inclusive)
	if (number>9||number<1) {
		valid=0;
		cout << "Number must be between 1 and 9 (inclusive)" << endl;
	}

	// test column: ensure the specified number is not already present in the column
	for (int i=0; i<9; i++) {
		if(puzzle[i][col]==number) {	// number is already in the column
			valid=0;		// marks location as invalid
		}
	}

	// test row: ensure the specified number is not already present in the row
	for (int j=0; j<9; j++) {
		if(puzzle[row][j]==number) {	// number is already in the row
			valid=0;		// marks location as invalid
		}
	}

	// test 3x3 grids: the bounds of a and b change depending on the target location
	// the if or else if that runs is based on the row/column specified
	if (row<3&&col<3) {		// top-left 3x3 grid
		for(a=0; a<3; a++) {
			for(b=0; b<3; b++) {
				if(puzzle[a][b]==number) {	// number is already in the grid
					valid=0;		// marks location as invalid
				}
			}
		}
	}
	else if(row<3&&col<6) {		// top-middle 3x3 grid
		for(a=0; a<3; a++) {
			for(b=3; b<6; b++) {
                                if(puzzle[a][b]==number) {	// number is already in the grid
                                        valid=0;		// marks location as invalid
                                }
			}
		}
	}
	else if(row<3&&col<9) {		// top-right 3x3 grid
		for(a=0; a<3; a++) {
                        for(b=6; b<9; b++) {
                                if(puzzle[a][b]==number) {	// number is already in the grid
                                        valid=0;		// marks location as invalid
                                }
			}
		}
	}
	else if(row<6&&col<3) {		// middle-left 3x3 grid
		for(a=3; a<6; a++) {
                        for(b=0; b<3; b++) {
                                if(puzzle[a][b]==number) {	// number is already in the grid
                                        valid=0;		// marks location as invalid
                                }
			}
		}
	}
	else if(row<6&&col<6) {		// middle-middle 3x3 grid
		for(a=3; a<6; a++) {
                        for(b=3; b<6; b++) {
                                if(puzzle[a][b]==number) {	// number is already in the grid
                                        valid=0;		// marks location as invalid
                                }
			}
		}
	}
	else if(row<6&&col<9) {		// middle-right 3x3 grid
		for(a=3; a<6; a++) {
                        for(b=6; b<9; b++) {
                                if(puzzle[a][b]==number) {	// number is already in the grid
                                        valid=0;		// marks location as invalid
                                }
			}
		}
	}
	else if(row<9&&col<3) {		// bottom-left 3x3 grid
		for(a=6; a<9; a++) {
                        for(b=0; b<3; b++) {
                                if(puzzle[a][b]==number) {	// number is already in the grid
                                        valid=0;		// marks location as invalid
                                }
			}
		}
	}
	else if(row<9&&col<6) {		// bottom-middle 3x3 grid
		for(a=6; a<9; a++) {
                        for(b=3; b<6; b++) {
                                if(puzzle[a][b]==number) {	// number is already in the grid
                                        valid=0;		// marks location as invalid
                                }
			}
		}
	}
	else if(row<9&&col<9) {		// bottom-right 3x3 grid
		for(a=6; a<9; a++) {
                        for(b=6; b<9; b++) {
                                if(puzzle[a][b]==number) {	// number is already in the grid
                                        valid=0;		// marks location as invalid
                                }
			}
		}
	}
	return valid;
}

// determines if the puzzle is complete (filled) yet; no blanks means the puzzle is complete
template< typename T>
int Puzzle<T>::isComplete() {
	int blanks=0;	// initializes number of empty squares remaining

	// loop through the 9x9 grid to find any empty spots
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if (puzzle[i][j]==0) {	// blank spot found
				blanks++;
			}
		}
	}
	return blanks;
}

// check that the space is empty
template< typename T>
int Puzzle<T>::isEmpty(int newrow, int newcol) {
	int status;	// status of the specified location: 1 is empty; 0 is filled
	int row=newrow;	// user specified row
	int col=newcol;	// user specified column

	if (puzzle[row][col]==0) {	// specified location is empty
		status=1;		// marks location as empty
	}
	else {				// specified location is not empty
		status=0;		// marks location as filled
	}
	return status;
}

// play the specified sudoku or wordoku puzzle
template< typename T>
void Puzzle<T>::play() {
	int complete=1;	// status of puzzle; 1 is incomplete, 0 is complete
	int empty=0;	// status of particular grid cell; 1 is empty, 0 is full
	char cont='y';	// game status; 'n' will quit, otherwise continue trying to solve
	cout << "Initial puzzle to solve:" << endl;
	display();

	// puzzle is not finished and a quit has not been specified
	while((complete!=0)&&(cont!='n')) {
		int row=-1, col=-1;	// resets the specified row and column so user can input new values
		while (row>8||row<0) {	// row values are between 0 and 8
			cout << "Select a row (0-8): ";
			cin >> row;
			if (row>8||row<0) {	// row selection is invalid
				cout << "Row must be between 0 and 8." << endl;
			}
		}
		while (col>8||col<0) {	// column values are between 0 and 8
			cout << "Select a column (0-8): ";
			cin >> col;
			if (col>8||col<0) {	// column selection is invalid
				cout << "Column must be between 0 and 8." << endl;
			}
		}
		empty=isEmpty(row, col);	// determines if the target spot is empty

		// target spot is empty
		if (empty==1) {	
			change(row, col);	// updates puzzle grid
			complete=isComplete();	// determine if the last move complete the grid
			cout << string(100, '\n');	// clears the screen
			cout << "The updated puzzle is:" << endl;
			display();			// displays the updated puzzle grid
		}
		// target spot is not empty
		else {
			cout << "Specified location is already full." << endl;
			cout << "Please specify an empty spot." << endl;
		}

		// if game is not completed yet
		if (complete!=0) {
			cout << "Continuing trying to solve? (y/n) ";
			cin >> cont;
		}
	}

	// game was completed
	if (complete==0) {
		cout << "You solved the puzzle!" << endl;
	}
	// game ended as incomplete
	else {
		cout << "Better luck next time!" << endl;
	}
}

#endif
