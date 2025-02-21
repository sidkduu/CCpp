#include<stdio.h>
#include<stdbool.h>

// һ�������˽ṹ��������һ���Լ�������������͡�
// ˵���ṹҲ������Ϊ��������

// int numberOfDays ( struct date d )
// �������ṹ������Ϊ������ֵ���뺯��
// �����ʱ�����ں������½�һ���ṹ�����������Ƶ����߽ṹ��ֵ
// ��Ҳ���Է���һ���ṹ
// ������������ȫ��ͬ
// ʾ�������ĳһ�����һ�������

// ����ṹ
// ��û��ֱ�ӵķ�ʽ����һ��scanf һ���ṹ
// ��������Ǵ���дһ������������ṹ��Subroutine1-11.2.2.1��  ���⣺�޷����ؽṹ��
// 	�����Ƕ���Ľṹ����ͻ����أ�
// 	��ע��C �ں������õ�ʱ���Ǵ�ֵ��
// 	�����Ժ���������p ����ֵ֮��û���κζ����ص�main������y ����{0��0}

// �������
// ��֮ǰ�ķ�������һ���ṹ�����˺�����Ȼ���ں����в���������û�з���ȥ
// ���������ڴ��뺯����������ṹ�Ŀ�¡�壬������ָ��
//         ---����ṹ�ʹ��������ǲ�ͬ��

// ����������뺯���У���ȫ���Դ���һ����ʱ�Ľṹ������Ȼ�������ṹ���ظ������ߡ�
// 		������Subroutine1 - 11.2.2.2 ��
// ������Ϊ��Ч�ķ�ʽ�Ǵ�ָ��

// �ṹָ����Ϊ����
// ��K & R ˵��
// ��"If a large structure is to be passed to a function, it is generally more efficient to pass a pointer than
//     to copy the whole structure."


struct date {
	int month;
	int day;
	int year;
};

bool isLeap(struct date d);
int numberOfDays(struct date d);

int main(int argc, char const* srgv[])
{
	struct date today = {}, tomorrow = {};

	printf("Enter today's date (mm dd yyyy): ");
	scanf("%i %i %i", &today.month, &today.day, &today.year);		// ����ṹ

	if (today.day != numberOfDays(today)) {
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if (today.month == 12){
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else {
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}

	printf("Tomorrow's date is %i-%i-%i.\n",
		tomorrow.year, tomorrow.month, tomorrow.day);

	return 0;
}

int numberOfDays(struct date d)
{
	int days;

	const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (d.month == 2 && isLeap(d) ) days = 29;
	else days = daysPerMonth[d.month - 1];

	return days;						
}

bool isLeap(struct date d)
{
	bool leap = false;

	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) leap = true;

	return leap;
}