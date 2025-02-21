#include<stdio.h>

struct point {
	int x;
	int y;
};

struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point* p);

int main(int argc, char const* argv[])
{
	struct point y = { 0, 0 };
	getStruct(&y);
	output(y);
	output(*getStruct(&y));		//getStruct函数返回值是一个指针，于是用*取出函数返回的那个东西作为一个变量来使用
	print(getStruct(&y));
	*getStruct(&y) = {1, 2};		//对函数返回值赋值

	return 0;
}

struct point* getStruct(struct point* p)
{
	scanf("%d", &p -> x);
	scanf("%d", &p -> y);
	printf("%d,  %d\n", p -> x, p -> y);
	return p;
}

void output(struct point p)
{
	printf("%d,  %d\n", p.x, p.y);
}

void print(const struct point* p)
{
	printf("%d,  %d\n", p->x, p->y);
}