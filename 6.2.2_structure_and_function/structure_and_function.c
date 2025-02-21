#include<stdio.h>
#include<stdbool.h>

// 一旦声明了结构，就有了一种自己定义的数据类型。
// 说明结构也可以作为函数参数

// int numberOfDays ( struct date d )
// ·整个结构可以作为参数的值传入函数
// ·这个时候是在函数内新建一个结构变量，并复制调用者结构的值
// ·也可以返回一个结构
// ·这与数组完全不同
// 示例：输出某一天的下一天的日期

// 输入结构
// ·没有直接的方式可以一次scanf 一个结构
// ·如果我们打算写一个函数来读入结构（Subroutine1-11.2.2.1）  问题：无法返回结构。
// 	·但是读入的结构如何送回来呢？
// 	·注：C 在函数调用的时候是传值的
// 	·所以函数读入了p 的数值之后，没有任何东西回到main，所以y 还是{0，0}

// 解决方案
// ·之前的方案，把一个结构传入了函数，然后在函数中操作，但是没有返回去
// ·问题在于传入函数的是外面结构的克隆体，而不是指针
//         ---传入结构和传入数组是不同的

// ·在这个输入函数中，完全可以创建一个临时的结构变量，然后把这个结构返回给调用者。
// 		·见（Subroutine1 - 11.2.2.2 ）
// ·但更为有效的方式是传指针

// 结构指针作为参数
// ·K & R 说过
// ·"If a large structure is to be passed to a function, it is generally more efficient to pass a pointer than
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
	scanf("%i %i %i", &today.month, &today.day, &today.year);		// 输入结构

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