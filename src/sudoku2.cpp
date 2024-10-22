//============================================================================
// Name        : sudoku2.cpp
// Author      : Alessandro S.
// Version     :
// Copyright   : D.A.S.
// Description : Standard sudoku grid generator
//============================================================================

#include <iostream>
#include "SudoAlgo.h"


int main() {
	cout << "main - info - begin" << endl;
	SudoAlgo sudo_algo(1); // generate 1 solution and then stop
	sudo_algo.generate();
//	sudo_algo.display();
	cout << "main - info - end" << endl;
	return 0;
}
