#include<stdio.h>
#include"max.h"
#include"main.h"

int main(int argc, char const* argv[])
{
	int a = 5, b = 6;
	printf("%f\n", max(a, b));
	printf("%f\n", max(a, gAll));		//��Ҫ��������Ŀĳ����һ��ȫ�ֱ���

	return 0;
}