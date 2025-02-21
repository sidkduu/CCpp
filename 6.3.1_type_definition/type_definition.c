#include<stdio.h>

int main()
{
	typedef long long int64_t;		//重载已有类型的名字，新名字的含义更清晰，具有可移植性
	typedef struct ADate {
		int month;
		int day;
		int year;
	} Date;				//简化了复杂的名字

	int64_t i = 100000000000;
	Date d = { 9,  1,  2005 };

	printf("%lli\n", i);
	printf("%i-%i-%i\n", d.year, d.month, d.day);

	return 0;
}