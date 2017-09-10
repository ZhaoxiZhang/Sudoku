#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku() {
	memset(board, 0, sizeof(board));
	board[0][0] = 6;               // (4 + 1) % 9 + 1
}

Sudoku::~Sudoku() {

}

bool Sudoku::validNum(int row, int col, int num) {
	//检查数独盘行列
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == num) {
			return false;
		}
		if (board[i][col] == num) {
			return false;
		}
	}

	//检查数独盘粗线宫 
	int rowLine = row - (row % 3);
	int colLine = col - (col % 3);
	for (int i = rowLine; i < rowLine + 3; i++) {
		for (int j = colLine; j < colLine + 3; j++) {
			if (board[i][j] == num) {
				return false;
			}
		}
	}

	return true;
}

bool Sudoku::generateBoard(int row, int col) {
	//终止条件 
	if (row == 8 && col == 9) {
		return true;
	}

	//按列填，填满一列，换行 
	if (col == 9) {
		row++;
		col = 0;
	}


	int randNum = (rand() % 9) + 1;

	for (int i = randNum; i <= 9; i++) {
		if (validNum(row, col, i)) {
			board[row][col] = i;

			//回溯 
			if (generateBoard(row, col + 1)) {
				return true;
			}
			else {
				board[row][col] = 0;
			}

		}
	}

	for (int i = randNum; i > 0; i--) {
		if (validNum(row, col, i)) {
			board[row][col] = i;

			//回溯 
			if (generateBoard(row, col + 1)) {
				return true;
			}
			else {
				board[row][col] = 0;
			}
		}
	}

	return false;
}


/*void Sudoku::displayBoard(ofstream& fout) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			j ? fout << " " << board[i][j] : fout << board[i][j];
			//j ? printf("%2d", board[i][j]) : printf("%d", board[i][j]);
		}
		//printf("\n");
		fout << endl;
	}
	//printf("\n");
	fout << endl;
}*/

void Sudoku::displayBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			//j ? fout << " " << board[i][j] : fout << board[i][j];
			j ? fprintf(stdout,"%2d", board[i][j]) : fprintf(stdout,"%d", board[i][j]);
		}
		fprintf(stdout,"\n");
		//fout << endl;
	}
	fprintf(stdout,"\n");
	//fout << endl;
}

