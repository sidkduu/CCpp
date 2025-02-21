#include<stdio.h>

int main()
{
	int x = 0;
	int n = 1;

	printf("请输入一个5位以内的正整数。\n");

	scanf("%d", &x);

	if (x > 999) {
		n = 4;
	}
	else 
	{
		if (x > 99) {
			n = 3;
		}
		else 
		{
			if (x > 9)
				n = 2;
		}
	}

	printf("x是%d位数。\n", n);

	//运用if-else if级联时如果判断时大于某值，应先判断是否大于较大的值。
	//运用级联，在一定范围内可用if - else if语句，位数过大时，应用循环。

	printf("下面尝试做循环。\n\n");

	int X = 0;
	int N = 0;

	printf("请输入一个整数。\n");

	scanf("%d", &X);

	N++;
	X /= 10;
	while (X > 0) {
		N++;
		X /= 10;
	}

	printf("X是%d位数。\n", n);

	return 0;
}

//int最大是十位。
