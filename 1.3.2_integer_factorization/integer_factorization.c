#include<stdio.h>
#include<string.h>

int main() {
	int a = 0;
	int t = 0;
	int e = 0;

	printf("现在开始做第一轮运算,分解一个整数。\n");
	printf("请输入一个整数:");
	
	scanf("%d", &a);

	e = a;

	do {
		int b = a % 10;
		t = t * 10 + b;
		a /= 10;
	} while (a > 0);
	
	printf("a = %d, t = %d;\n", a, t);
	printf("a原先=%d;\n", e);
	printf("下面输出结果：\n");

	a = t;								//此时a经一系列运算已不是原值，需重新赋值；
	
	do {
		int b = a % 10;
		printf("%d", b);
		if (a > 9) {
			printf(" ");
		}
		else {
			printf(";");
		}
		a /= 10;
	} while (a > 0);
	
	printf("\n\n");						//连续两次do-while，逆序输出再逆序输出。
	printf("不难看出程序是有漏洞的, 即个位数不能为0。\n\n");
	printf("hr\n");//在上一行插入断点
	
	printf("现在尝试输出输入整数为7000的情况。\n");
	
	int x = 7000;
	int p = 0;

	do {
		int c = x % 10;
		p = p * 10 + c;
		x /= 10;
	} while (x > 0);
	
	printf("x = %d, p = %d; \n", x, p);
	printf("x原先等于7000;\n");
	printf("下面输出结果：\n");

	x = p;

	do {
		int c = x % 10;
		printf("%d", c);
		if (x > 9) {
			printf(" ");
		}
		else {
			printf(";");
		}
		x /= 10;
	} while (x > 0);

	printf("\n\n");
	printf("本应输出7000, 但是输出了7, 结果错误。\n\n\n");
	printf("hr\n");//在上一行插入断点

	printf("现在开始做第二轮整数分解。\n\n");

again:
	char k;

	printf("请输入一个整数:");

	int m = 0;
	int m1 = 0;
	int mask = 1;
	
	scanf("%d", &m);

	m1 = m;
	while (m1 > 9) {
		m1 /= 10;
		mask *= 10;
	}

	printf("m = %d, mask = %d;\n", m, mask);
	printf("下面输出结果：");

	do {
		int n = m / mask;
		printf("%d", n);
		if (mask >= 10) {
			printf(" ");
		}
		else {
			printf(";");
		}
		m %= mask;
		mask /= 10;
	} while (mask > 0);

	printf("\n");
	printf("此时，程序完美运行!\n");
	printf("要继续吗?输入else即可继续运行。\n");

	scanf("%c", &k);
		
	if (k == 'else') {
		goto again;
	}
	else {
		return 0;
	}
}

// 正序分解整数
// ·输入一个非负整数，正序输出它的每一位数字

// 22/11/1 无法让其循环进行