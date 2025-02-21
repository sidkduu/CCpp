#include<stdio.h>

// 编译预处理指令
// ·#开头的是编译预处理指令
// ·它们不是C 语言的成分，但是C 语言程序离不开它们
// ·#define 来定义一个宏

// .c -> .i -> .s -> .o -> a.out
// 源代码.c 经过编译预处理（把编译预处理指令都执行完( 替换宏之类的 )）得到了编译预处理后的中间结果文件.i
// .i 由C 的编译器编译真正产生了汇编代码文件.s
// .s 做汇编变成目标代码文件.o
// .o 再经过链接器和其他东西链接（加上库代码和启动代码）得到最终可执行的东西.out( .exe )

// #define
// ·#define <名字> <值>
// ·注意没有结尾的分号，因为不是C 的语句
// ·名字必须是一个单词，值可以是各种东西
// ·在C 语言的编译器开始编译之前，编译预处理程序（cpp）会把程序中的名字换成值
// 	·完全的文本替换
// ·gcc——save-temps

// 宏
// ·如果一个宏的值中有其他的宏的名字，也是会被替换的
// ·如果一个宏超过一行，最后一行之前的行末需要加\
// ·宏的值后面出现的注释不会被当作宏的值一部分

// 没有值的宏
// ·#define _DEBUG
// ·这类宏是用于条件编译的编译的，
//     后面有的编译预处理指令来检查这个宏是否已经被定义过了

// 预定义的宏
// ·__LINE__ 源代码文件的行号（十进制常量）
// ·__FILE__ 源代码文件的文件名（字符串常量）
// ·__DATE__ 编译时的日期 （字符串常量）
// ·__TIME__ 编译时的时间（字符串常量）
// ·__STDC__  当编译器以ANSI标准编译时，则定义为1；
// 		  （判断是不是标准C 程序）

// 像函数的宏
// ·#define cube(x) ((x)*(x)*(x))
// ·宏可以带参数
// ·可以一定程度上代替定义函数

// 错误地定义宏
// ·#define RADTODEG1(x) (x * 57.29578)
// ·#define RADTODEG2(x) (x )* 57.29578

// 带参数的宏的定义原则
// ·一切都要括号
//     ·整个值要括号
//     ·参数出现的地方要括号
// ·#define RADTODEG(x) ((x)* 57.29578)

// 带参数的宏
// ·可以带多个参数
//     ·#define MIN(a, b) ((a)>(b)?(b):(a))
// ·也可以组合(嵌套)使用其他宏

// 分号？
// ·在宏定义时，最后千万不要加分号（宏不是C 语句）
// ·#开头的预处理指令不是C 语言，许多语言如汇编语言也可以使用
// #define PRETTY_PRINT(msg) printf(msg)

// if(n<10)
// 	PRETTY_PRINT("n is less than 10");
// else
// 	PRETTY_PRINT("n is at least 10");

// 带参数的宏
// ·在大型程序的代码中使用非常普遍（运行效率比函数高）（代码大小比调用函数大）
// ·可以非常复杂，如“产生”函数
//     ·在#和##这两个运算符的帮助下，可以做出产生新函数的程序
// ·存在中西方文化差异，中国程序员较少使用宏
// ·部分宏会被inline替代
// ·宏的缺点：传递参数时不存在类型检查，在传递参数的时候也不存在类型

// ##的用法
// 用于把参数宏中的“形参”与其他没有天然分割的内容粘连在一起，例如：
// #define def_u32_array(__name, __size) unit32_t array_##__name[__size];
// 实际使用场景：
// def_u32_array(sample_buffer, 64)
// 宏展开的效果是
// unit32_t array_sample_buffer[64] 

// 不需要画蛇添足地使用"##"

#define PI 3.14159
#define FORMAT "%f\n"
#define PI2 2.0 * PI				//pi * 2 

#define PRT printf("%f ", PI); printf("%f ", PI2); \
					printf("%f\n\n", 2.0 * PI);

#ifdef __STDC_HOSTED__ \
	printf("标准C代码文件\n")
#else
	printf("非标准C代码文件\n")
#endif

#define cube(x) ((x)*(x)*(x))
#define RADTODEG1(x) (x * 57.29578)
#define RADTODEG2(x) (x) * 57.29578
#define RADTODEG3(x) (x * 57.29578)
#define RADTODEG4(x) ((x) * 57.29578)

// const double PI = 3.14159
constexpr auto E = 2.71828;		//后面不能跟分号;

int main(int argc, char const* argv[])
{
	printf("%f\n", 2 * PI * 3.0);
	printf(FORMAT, PI2 * 3.0);
	printf(FORMAT, E);
	PRT
		printf("%s:%d\n", __FILE__, __LINE__);
	printf("%s:%s\n\n", __DATE__, __TIME__);

	printf("%d\n", __STDC_HOSTED__);				//若实现有宿主（运行在OS下）则展开成整数常量1，若实现自立（不随OS运行），则展开成0
	printf("%d\n", __cplusplus);							//代表所用的C++标准版本。取值可能为199711，201101，201412，201701，202002

	int a = 0;
	scanf("%d", &a);
	printf("%d\n\n", cube(a+2));

	printf("%f\n", RADTODEG1(5+2));
	printf("%f\n", static_cast<double>(180)/ RADTODEG2(1));
	printf("%f\n", RADTODEG3((5 + 2)));
	printf("%f\n", static_cast<double>(180) / RADTODEG4(1));

	return 0;
}