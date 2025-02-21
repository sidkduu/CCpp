#include<stdio.h>
#include<stdbool.h>

// 	C语言是有类型的语言
//  c语言的变量，必须在使用前定义，并且确定类型
// ·C以后的语言向两个方向发展：
//  ·C++/Java更强调的类型，对类型检查不严格；
//  ·JavaScript、Python、PHP不看重类型，甚至不需要事先定义。

// 	类型安全
// ·支持强类型的观点认为明确的类型有助于尽早发现程序中的简单错误
// ·反对强类型的人认为过于强调类型迫使程序员面对底层、实现而非事务逻辑


// 	C语言的类型
// ·整数
//  ·char、short、int、long、long long
// ·浮点数
//  ·float、double、long double
// ·逻辑
//  ·bool
// ·指针
// ·自定义类型


// 	类型有何不同
// ·类型名称：int、long、double
// ·输入输出时的格式化：%d、%ld、%lf
// ·所表达的数的范围：char < short < int < float < double
// ·内存中所占据的大小：1个字节到16个字节
// ·内存中的表达形式：二进制数（补码）、编码


// sizeof是一个运算符，给出某个类型的变量在内存中所占据的字节数
// ·sizeof（int）

// sizeof可以做什么
// （“%zd”，sizeof（int））
// =4，一个字节是八个比特，四个字节则为32位。

// sizeof是静态运算符，结果在编译时就决定了。（）括号内的算符不做计算。

int main()
{
	int a = 0;
	a = 6;
	
	printf("a=%d", a);
	printf("sizeof(int)=%zd\n", sizeof(int));
	printf("sizeof(a++)=%zd\n", sizeof(a++));		
	printf("a=%d\n\n", a);
	printf("sizeof(char)=%zd\n", sizeof(char));
	printf("sizeof(short)=%zd\n", sizeof(short));
	printf("sizeof(long int)=%zd\n", sizeof(long int));
	printf("sizeof(long)=%zd\n", sizeof(long));
	printf("sizeof(long long)=%zd\n", sizeof(long long));
	printf("sizeof(long long int)=%zd\n", sizeof(long long int));
	printf("sizeof(float)=%zd\n", sizeof(float));
	printf("sizeof(double)=%zd\n", sizeof(double));
	printf("sizeof(long double)=%zd\n", sizeof(long double));
	printf("sizeof(unsigned)=%zd\n", sizeof(unsigned));
	printf("sizeof(bool)=%zd\n", sizeof(bool));

	return 0;
}