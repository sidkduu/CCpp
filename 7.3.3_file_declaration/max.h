#ifndef _MAX_H_			//条件编译指令	//如果没有定义这个宏
#define _MAX_H_									//那么定义这个宏			（如果定义过，那么下面的部分就不会出现在.i 文件中（可以避免重定义））

double max(double a, double b);
extern double gAll;			//告诉编译器在项目某一个地方有一个int类型的gAll

struct Node {
	int value;
	char* name;
};

#endif

//或用#pragma once	