#include<stdio.h>

// 一、全局变量
// ·定义在函数外面的变量是全局变量
// ·全局变量具有全局的生存期和作用域
//     ·它们与任何函数都无关
//     ·在任何函数内部都可以使用它们


// 二、全局变量初始化
// ·没有做初始化的全局变量会得到0 值（本地变量不会）
// ·指针会得到NULL值
// ·只能用编译时刻已知的值来初始化全局变量
// ·它们的初始化发生在main函数之前


// 三、被隐藏的全局变量
// ·如果函数内部存在与局部变量同名的变量，则全局变量被隐藏。
// ·更小的范围内，定义局部变量隐藏较大范围的同名变量。

// 静态本地变量
// ·在本地变量定义时加上static 修饰符就能成为静态本地变量
// ·当函数离开的时候，静态本地变量会继续存在并保持其值
// ·静态本地变量的初始化只会在第一次进入这个函数时做，
//     以后进入函数时会保持上次离开时的值。

// 静态本地变量
// ·静态本地变量实际上是特殊的全局变量
// ·它们位于相同的内存区域（打开地址可看见）
// ·但是他被放在函数内
// ·静态本地变量具有全局的生存期，函数内的局部作用域（本地作用域）
// ·static 在这里的意思是局部作用域（本地可访问）

// *返回指针的函数
// ·返回本地变量的地址是很危险的
// 	·函数结束后本地变量的地址会继续分配给别人使用
// ·返回全局变量或静态本地变量的地址是安全的
// ·返回在函数内malloc 的内存是安全的，但容易造成问题（malloc后要free）
// ·最好的做法是返回传入的指针

// TIPS
// ·不要使用全局变量来在函数间传递参数和结果
// ·尽量避免使用全局变量
// ·*使用全局变量和静态本地变量的函数是（不可重入）线程不安全的（多线程的环境）。


int fg(void);
int pg(void);

int fs(void);
int hs(void);

int* ftips(void);
void gtips(void);

int gAll = 12;									//全局变量作用域大于所有函数，因此在所有函数中都可以使用这个全局变量
int g2 = gAll;
int hAll = 100;

int main(int argc, char const* argv[])
{
	// global variable
	printf("in %s gAll = %d\n", __func__, g2);		//__func__ 是一个字符串，表达的是当前函数（mian）的名字 //让编译器替我们把函数的名字输入打印
	fg();
	printf("agn in %s gAll = %d\n\n", __func__, gAll);

	printf("in %s hAll = %d\n", __func__, hAll);
	pg();
	printf("agn in %s hAll = %d\n", __func__, hAll);

	// static variable
	fs();
	fs();
	fs();
	hs();

	// Tips
	int* p = ftips();
	printf("*p = %d\n", *p);			//期待得到12
	gtips();
	printf("*p = %d\n", *p);			//*p = 24

	return 0;
}

int fg(void)
{
	printf("in %s gAll = %d\n", __func__, gAll);		//__func__ 是一个字符串，表达的是当前函数（f）的名字
	gAll += 2;
	printf("agn in %s gAll = %d\n", __func__, gAll);
	
	return gAll;
}

int pg(void)
{
	printf("in %s hAll = %d\n", __func__, hAll);
	int hAll = 1;
	printf("and in %s hAll = %d\n", __func__, hAll);
	{
		int hAll = 2;
		printf("next in %s hAll = %d\n", __func__, hAll);
		hAll += 3;
		printf("and in %s hAll = %d\n", __func__, hAll);
	}
	printf("agn in %s hAll = %d\n", __func__, hAll);
	hAll += 1;
	printf("and in %s hAll = %d\n", __func__, hAll);

	return hAll;
}

int fs(void)
{
	int all = 1;
	static int All = 1;

	printf("in %s all = %d\n", __func__, all);
	all += 2;
	printf("agn in %s all = %d\n,\n", __FUNCTION__, all);
	
	printf("In %s All = %d\n", __func__, All);
	All += 2;
	printf("Agn in %s All = %d\n\n\n", __FUNCTION__, All);

	return all;
}

int hs(void)
{
	int k = 0;
	static int m = 1;

	printf("&gAll =  %p\n", &gAll);
	printf("&m    =  %p\n", &m);
	printf("&k    =  %p\n", &k);

	return 0;
}

int* ftips(void)
{
	int i = 12;
	printf("& i = % p\n", &i);
	return &i;
}

void gtips(void)
{
	int k = 24;
	printf("& k = % p\n", &k);
	printf("k = %d\n", k);
}
