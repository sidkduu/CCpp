#include<stdio.h>

// 浮点类型
// float               字长：32		范围:~+-（1.2*10^-38~1.2*10^38）,0,+-inf,nan;
// 		有效数字：7（位）		
// double           字长：64		范围:~+-（2.2*10^-308~1.79*10^308）,0,+-inf,nan;	
// 		有效数字：15（位）

// 浮点类型的输入和输出
// float 		scanf：%f		printf：%f，%e（科学计数）
// double	scanf：%lf		printf：%f，%e（科学计数）

// %.2f中可以指定要输出多少位小数（此处是2位），输出时做四舍五入。

// 计算机内，小数位特别小的数不能被准确表达，计算机会选择离输入数最近的数实际输入，
// 这个就造成了浮点数的误差，double比float精度更高，但是仍然无法准确表达
// （可以用两个整数做商准确表达一个浮点数。）


// 浮点数的表达范围与精度
// inf -- 无穷大
// nan -- 不存在

// 整数/0无法编译通过
// 浮点数/0则表示该数不存在。

// · 带小数点的字面量是double而非float
// · float需要用f或F后缀来表明身份

// · f1 == f2 可能失败
// · fabs（f1 - f2）< 1e-12;  (判定浮点数相等，求绝对值相差，只要小于有效数即可判定相等
// 				，保险起见，判断值比有效值小一点（多个浮点数相加误差会累积）)

// ·算钱的时候，通常用“分”做单位，以整数形式表达。
// ·可以以bcd数表达，传统计算器以bcd做表达


// 浮点数的内部表达
// ·浮点数在计算时是由专用的硬件部件实现的
// ·计算double和float所用的部件是一样的

// 选择浮点类型
// ·如果没有特殊需要，只用double
// ·现代cpu能直接对double做硬件运算，性能不会比float差，
// 	在64位的机器上，数据存储的速度也不会比float慢。

int main()
{
	// integer formatting
	char c = -1;
	int i = -1;
	printf("c=%u,i=%u\n", c, i);
	char d = 012;
	int j = 0x12;
	// 八进制输出、十六进制输出
	printf("d=%o,j=%X\n", d, j);

	// type_conversion
	int i = 32768;
	short s = (short)i;
	printf("%d\n", i);

	// floating point type
	double ff = 1234.56789;
	printf("%e\n%E\n%f\n\n", ff, ff, ff);

	double fff = 49E-5;
	printf("%.16f\n", fff);
	printf("%.64f\n\n", fff);

	double a = 0.45;
	printf("%.1f\n", a);

	// flote type compare
	float a = 0, b = 0, c = 0;

	a = 1.345f;
	b = 1.123f;
	c = a + b;
	if (c == 2.468)
		printf("Isequal\n");
	else
		printf("Unequal!  c = %.10f, else%f\n", c, c);

	return 0;
}