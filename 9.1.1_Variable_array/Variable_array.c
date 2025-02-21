#include<stdio.h>
#include<stdlib.h>
#include"array.h"

const int BLOCK_SIZE = 20;

int main()
{
	Array a = array_create(100);
	printf("this array size=%d\n", array_size(&a));				//后面参数写a.size不够严谨
	//*array_at(&a, 0) = 10;													//函数返回值所指的东西，可以做左值，可以做变量			//这句话可以把值写到数组里面去
	array_set(&a, 0, 11);
	printf("a[0]=%d\n", *array_at(&a, 0));
	
	int number=0;
	int cnt = 1;
	while (number != -1) {
		scanf("%d", &number);
		if (number != -1) {
			*array_at(&a, cnt++) = number;
			printf("a[%d]=%d\n",cnt-1, array_get(&a, cnt-1));
		}
	}
	array_free(&a);

	return 0;
}

Array array_create(int init_size)										//创建一个数组（参数为一开始希望数组的大小）
{
	Array a = {};
	a.size = init_size;
	a.array = (int*)malloc(sizeof(int) * a.size);
	return a;
}
//返回类型是Array的原因，返回指针会使本地变量无效；malloc一个Array的结构会使对Array的使用比较复杂；返回结构体也便于在主函数中操作返回后的值
//结构体指针要分配空间才能使用，如果返回指针形式的话，需要先传入结构体指针，有可能指针指向null，也有可能指针指向曾经制作出的数组
//不见得是最优解

void array_free(Array* a)
{
	free(a->array);
	a->array = NULL;			//防止别人调用两次函数
	a->size = 0;					//保险起见
}
//如果已经有了一个Array，但a本身是本地变量，在离开main后空间会被回收。但a中含有指针变量，需要有恰当的方式释放它
//此函数是要free 那个a所指的array

//封装 保护a的size，防止size的值被随意修改
int array_size(const Array* a)
{
	return a->size;
}
//得到现在数组有多少单元

int* array_at(Array* a, int index)
{
	if (index >= a->size) {
		array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);					//维持了inflate功能不变，因为不一定只需增长一个block
	}
	return &(a->array[index]);					//返回类型为指针，返回参数上要加取地址符，加括号分优先级即可
}
//返回类型为指针的原因:返回值可以做左值；方便在主函数中赋值

//下面给出一套赋值函数
int array_get(const Array* a, int index)
{
	return a->array[index];
}
//用在printf，得到那个数组的值
void array_set(Array* a, int index, int value)
{
	a->array[index] = value;
}
//对数组赋值


void array_inflate(Array* a, int more_size)
{
	int* p = (int*)malloc(sizeof(int) * (a->size + more_size));				//申请一块新的空间
	//将老的空间复制到新的空间上去
	for (int i = 0; i < a->size; i++) {
		p[i] = a->array[i];
	}//拷贝到原来数组里的所有东西
	free(a->array);
	a->array = p;
	a->size += more_size;
}