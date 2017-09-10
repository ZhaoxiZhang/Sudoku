#include "Process.h"
#include<cstring>

Process::Process() {

}

Process::~Process() {

}

bool Process::isNumber(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

int Process::convertToNum(char* str) {
	int len = strlen(str);
	int res = 0, tmp = 1;
	for (int i = len - 1; i >= 0; i--) {
		res += (str[i] - '0')*tmp;
		tmp *= 10;
	}
	return res;
}