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
		printf("你输入的执行参数有误\n用法：sudoku.exe -c <number>(需要生成的数独盘数目)\n");
	}
	else {
		if (!process.isNumber(argv[2])) {
			printf("你输入的数独盘数目不合法\n用法：sudoku.exe -c <number>(需要生成的数独盘数目)\n");
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