#include<stdio.h>

void prtBin(unsigned int number);

struct U0 {
	unsigned int leading : 3;				//这个成员占几个比特
	unsigned int FLAG1 : 1;
	unsigned int FLAG2 : 1;
	int trailing : 27;							//如果没有trailing 结构体仍输出长度为4，但前27位因未赋初值是乱码
};

int main(int argc, char const* argv[])
{
	struct U0 uu {
		uu.leading = 2,
		uu.FLAG1 = 0,
		uu.FLAG2 = 1,
		uu.trailing = 4,
	};
	printf("sizeof(uu)=%zu\n", sizeof(uu));		//4（一个int的大小）
	prtBin(*(int*)&uu);									//取出uu的地址（指向struct U0的指针），强制类型转换为指向int的指针，再取这个指针所指的int

	return 0;
}

void prtBin(unsigned int number)
{
	unsigned mask = 1u << 31;
	for (; mask; mask >>= 1) {
		printf("%d", number & mask ? 1 : 0);
	}
	printf("\n");
}