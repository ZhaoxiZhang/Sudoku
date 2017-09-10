#include<ctime>
#include<cstdlib>
#include<cstdio>
#include "sudoku.h"
#include "process.h"
using namespace std;


int main(int argc,char* argv[]) {
	Process process;

	//Usage: sudoku.exe -c <number>
	if (strcmp(argv[1], "-c") != 0) {
		printf("�������ִ�в�������\n�÷���sudoku.exe -c <number>(��Ҫ���ɵ���������Ŀ)\n");
	}
	else {
		if (!process.isNumber(argv[2])) {
			printf("���������������Ŀ���Ϸ�\n�÷���sudoku.exe -c <number>(��Ҫ���ɵ���������Ŀ)\n");
		}
		else {
			ofstream fout;
			fout.open("./sudoku.txt");
			int n = process.convertToNum(argv[2]);
			srand((unsigned int)time(NULL));
			while (n--) {
				Sudoku sudoku;
				sudoku.generateBoard(0, 1);
				sudoku.displayBoard(fout);
			}
			fout.close();
		}
	}
	//system("pause");
	return 0;
}