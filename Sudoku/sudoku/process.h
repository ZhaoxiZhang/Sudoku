#pragma once
#ifndef __PROCESS_H_
#define __PROCESS_H_

class Process {
private:
public:
	Process();
	~Process();
	bool isNumber(char* str);
	int convertToNum(char* str);
};

#endif