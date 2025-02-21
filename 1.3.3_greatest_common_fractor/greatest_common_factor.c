// 求最大公约数
// 1.输入两个数a和b，输出他们的最大公约数；
// ·枚举法
// ·辗转相除法
#include<stdio.h>

int main()
{
	//第一种算法，枚举法
	printf("进行第一种算法-枚举法:\n");
	int a = 0;
	int b = 0;
	int min = 0;

	scanf("%d %d", &a, &b);
	if (a < b) {
		min = a;
	}
	else {
		min = b;
	}
	int ret = 0;
	int i = 0;
	for (i = 1; i <= min; i++) {
		if (a % i == 0 && b % i == 0) {
			ret = i;
		}
	}

	printf("%d和%d的最大公约数是%d.\n\n\n", a, b, ret);
	printf("下面开始进行第二种算法-辗转相除法：\n");

	int c = 0;
	int d = 0;
	int t = 0;

	scanf("%d %d", &c, &d);

	while (d != 0) {
		t = c % d;
		c = d;
		d = t;
		printf("c = %d,d = %d,t = %d;\t\n", c, d, t);
	}
	printf("gcd = %d\n", c);
}