#pragma once
#ifndef __GENERATOR_H_
#define __GENERATOR_H_
#include<fstream>
using namespace std;
class Sudoku {
private:
	int board[9][9];
	bool validNum(int row, int col, int num);
public:
	Sudoku();
	~Sudoku();
	bool generateBoard(int row, int col);
	void displayBoard(ofstream &fout);
};

#endif