//============================================================================
// Name        : sudoku2.cpp
// Author      : Alessandro S.
// Version     :
// Copyright   : D.A.S.
// Description : Standard sudoku grid generator
//============================================================================

#include <iostream>
#include "SudoAlgo.h"

int main(int argc, char **argv) {
	cerr << "main - debug - begin" << endl;
	unsigned int i = 1;
	if ( argc > 1 )
		try {
		i = stoi(argv[1]);
		}
		catch (...) {
			cout << "main - err - You can pass the number of grids per parameter. Default: 1." << endl <<
					"main - err - Example: " << argv[0] << " 2." << endl <<
					"main - err - Passing 0 as argument will print out all the solutions." << endl;
		}
	SudoAlgo sudo_algo(i); // generate 1 solution and then stop
	sudo_algo.generate();
//	sudo_algo.display();
	cerr << "main - debug - end" << endl;
	return 0;
}
