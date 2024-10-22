/*
 * SudoAlgo.cpp
 *
 *  Created on: 21 oct. 2024
 *      Author: salsettia
 */

#include <iostream>
#include "SudoAlgo.h"


/**
 * SudoAlgo::SudoAlgo initialize the number of grid to generate.
 * @i: number of solution. 0 if all.
 */
SudoAlgo::SudoAlgo(unsigned int i) : iter(i) {
	// TODO Auto-generated constructor stub

}


SudoAlgo::~SudoAlgo() {
	// TODO Auto-generated destructor stub
}


/**
 * SudoAlgo::display display the complete grid to cout
 */
void SudoAlgo::display() {
	cout << "SudoAlgo::display - info - Solution n°" << ++solution_nr << endl;
	cout << "-------------------------" << endl;
	unsigned int sep_x = 0, sep_y = 0;
	for ( unsigned int y = 0; y < 9; y++ ) {
			cout << "| ";
		for (unsigned int x = 0; x < 9; x++ ) {
			cout << grid[y][x] << " ";
			if ( ++sep_x == 3 ) {
				cout << "| ";
				sep_x = 0;
			}
		}
		cout << endl;
		if ( ++sep_y == 3 ) {
			cout << "-------------------------" << endl;
			sep_y = 0;
		}
	}
}


/**
 * SudoAlgo::decode calculates the position in the complete grid and position in the small grid 3x3.
 *
 * @i : index of the cell [0..80]
 * @x : position x in the complete grid
 * @y : position y in the complete grid
 * @square_x: position of the small grid 3x3
 * @square_y: position of the small grid 3x3
**/
void SudoAlgo::decode(unsigned int i, unsigned int &x, unsigned int &y, unsigned int &square_x, unsigned int &square_y) {
	y = i / 9;
	x = i % 9;
	square_y = y / 3;
	square_x = x / 3;
/*	square_y = (y = i / 9) / 3; // shorter version
	square_x = (x = i % 9) / 3;*/
}


/**
 * SudoAlgo::generate generates a grid and when complete return true
 *
 * @depth: index of the cell of the complete grid
 * @return true if a complete grid has been generated
 */
bool SudoAlgo::generate(unsigned int depth) {
	if ( depth <= 80 ) {
		unsigned int x, y, square_x, square_y;
		decode(depth, x, y, square_x, square_y);
//		cerr << "SudoAlgo::generate - debug - {depth} = {" << depth << "}" << endl;
		for ( unsigned int i = 1; i <= 9; i++) {
			if ( !square[square_y][square_x].contains(i) && !column[x].contains(i) && !row[y].contains(i) ) {
				square[square_y][square_x].insert(i); column[x].insert(i); row[y].insert(i);
				grid[y][x] = i;
				if ( generate(depth+1) && iter == solution_nr ) return true;
//				cerr << "SudoAlgo::generate - debug - {depth} = {" << depth << "}" << endl;
				square[square_y][square_x].erase(i); column[x].erase(i); row[y].erase(i);
			}
		}
		return false;
	}
	else {
		display();
		return true;
	}
}
