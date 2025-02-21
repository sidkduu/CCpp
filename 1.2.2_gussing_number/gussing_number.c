#include<stdio.h>
#include<stdlib.h>	//standard library标准库头文件
#include<time.h>	//C语言时间头文件，从系统时钟获取时间方式

int main()
{
	srand(time(0));//srand()是随机数发生器的初始化函数，和rand()配合使用产生伪随机数序列。//time()函数是返回自Unix纪元起当前时间秒数的函数，主要用来获取当前的系统时间，返回的结果是一个time_t类型。

	int number = rand() % 100 + 1;
	int count = 0;
	int a = 0;

	printf("我已经想好了一个1到100之间的数。\n");

	do {
		printf("请猜猜这个1到100之间的数：");
		scanf("%d", &a);

		count++;

		if (a > number) {
			printf("你猜的数大了。\n");
		}
		else if (a < number) {
			printf("你猜的数小了。\n");
		}
	} while (a != number);

	printf("太好了，你用了%d次就猜到了答案。\n", count);

	return 0;
}