/*
 * SudoAlgo.h
 *
 *  Created on: 21 oct. 2024
 *      Author: salsettia
 */

#ifndef SUDOALGO_H_
#define SUDOALGO_H_

#include <unordered_set>
using namespace std;

typedef unordered_set<int> number_set;

class SudoAlgo {
public:
	SudoAlgo(unsigned int i = 0);
	virtual ~SudoAlgo();
	void display();
	bool generate(const unsigned int i = 0);
	bool search(const unsigned int i = 0);
private:
	unsigned int grid[9][9];
	number_set column[9];
	number_set row[9];
	number_set square[3][3];
	unsigned int solution_nr = 0;
	unsigned int iter;

	void decode(unsigned int i, unsigned int &, unsigned int &, unsigned int &, unsigned int &);
};

#endif /* SUDOALGO_H_ */
