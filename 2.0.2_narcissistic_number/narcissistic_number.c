#include<stdio.h>

// 水仙花数是一个N位正整数（N >= 3），它的每个位上的数字的N次幂之等于它本身。例如：
// 153 = 1^3+5^3+3^3。要求计算三至七位的水仙花数，输入N位，输出此位所有的水仙花数。
int main()
{
	int n = 0;
	int first = 1;

	scanf("%d", &n);
	
	for (int i = 1; i < n; i++) {
		first *= 10;
	}

	int a = first;

	while (a < first * 10) {
		int t = a;
		int sum = 0;

		do {
			int d = t % 10;
			t /= 10;

			int p = 1, j = 0;
			
			while (j < n) {
				p *= d;
				j++;
			}
			sum += p;

		} while (t > 0);
		
		if (sum == a) {
			printf("%d\n", a);
		}
		
		a++;
	}
}