#include<stdio.h>

int main()
{
	typedef long long int64_t;		//�����������͵����֣������ֵĺ�������������п���ֲ��
	typedef struct ADate {
		int month;
		int day;
		int year;
	} Date;				//���˸��ӵ�����

	int64_t i = 100000000000;
	Date d = { 9,  1,  2005 };

	printf("%lli\n", i);
	printf("%i-%i-%i\n", d.year, d.month, d.day);

	return 0;
}