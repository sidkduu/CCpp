#include<stdio.h>

// 判断素数
//  ·去掉偶数后，从3到x-1，每次加2，当n很大时就是n/2遍
//  ·无需走到x-1，走到sqrt（x）就足够了，只需循环sqrt（x）遍。
//  ·判断能否能被已知的且  <x  的素数整除

int isPrime(int x, int knownPrimes[], int number0fKnownPrimes);

int main(void)
{
	const int number = 10;
	int prime[number] = { 2 };
	int count = 1;
	int i = 3;

	{
		int i;
		
		printf("\t\t");
		for (i = 0; i < number; i++) {
			printf("%d\t", i);
		}
		printf("\n");
	}

	while (count < number) {
		if (isPrime(i, prime, count)) {
			prime[count++] = i;				//写进数据，把指针往后移一位
		}
		
		{
			printf("i=%d\tcnt=%d\t", i, count);
			int i;
			
			for (i = 0; i < number; i++) {
				printf("%d\t", prime[i]);
			}
			printf("\n");
		}
		
		i++;
	}

	printf("\n");

	for (i = 0; i < number; i++) {
		printf("%d", prime[i]);
		if ((i + 1) % 5)printf("\t");
		else printf("\n");
	}

	return 0;
}

int isPrime(int x, int knownPrimes[], int number0fKnownPrimes)
{
	int ret = 1;
	int i;
	
	for (i = 0; i < number0fKnownPrimes; i++) {
		if (x % knownPrimes[i] == 0) {
			ret = 0;
			break;
		}
	}

	return ret;
}