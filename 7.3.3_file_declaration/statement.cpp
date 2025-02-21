#include<stdio.h>
#include"max.h"
#include"main.h"

int main(int argc, char const* argv[])
{
	int a = 5, b = 6;
	printf("%f\n", max(a, b));
	printf("%f\n", max(a, gAll));		//需要声明在项目某处有一个全局变量

	return 0;
}