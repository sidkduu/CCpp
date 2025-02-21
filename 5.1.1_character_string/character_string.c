#include<stdio.h>
#include<string.h>

// 1.字符串
// ·以0（整数0）结尾的一串字符
// ·0或‘\0’是一样的，但是和‘0’不同
// ·0标志字符串的结束，但它不是字符串的一部分
// ·计算这个字符串长度的时候不包含这个0
// ·字符串以数组形式存在，以数组或指针的形式访问（更多的是以指针的形式）
// ·string.h里有很多处理字符串的函数

// ·C语言的字符串是以字符数组的形态存在的
// ·不能用运算符对字符串做运算
// ·通过数组的方式可以遍历字符串
// ·唯一特殊的地方是字符串字面量可以用来初始化字符数组
// ·C的标准库提供了一系列字符串函数


// 字符串变量
// ·char  *str  =  "Hello"；
// ·char word[]  =  "Hello"；
// ·char line[10]  =  "Hello";

// 字符串常量
// ·“Hello”
// ·“Hello”会被编译器变成一个字符数组放在某处，这个数组的长度是6，结尾表示结束的0
// ·两个相邻的字符串常量会被自动连接起来。

// 2.字符串赋值？
// char*t  =  “title”；
// char*s；
// s  =  t；
// ·并没有产生新的字符串，只是让指针s指向t所指的字符串，
//  对s的任何操作就是对t做的。

// 字符串输入输出
// ·char string[8];
// ·scanf("%s", string);
// ·printf("%s", string);


// ·scanf读入一个单词（到空格、tab或回车为止）
// ·scanf是不安全的，因为不知道要读入内容的长度。（如果字符串中间有空格，就无法读完整个字符串）

// 安全地输入
// ·char string[8];
// ·scanf("%7s", string);
// ·在%和s之间的数字表示最多允许读入的字符的数量，这个数字应该比数组的大小小一
// ·下一次scanf从哪里开始？

// 常见错误
// ·char*string；
// ·scanf（"%s"，string）；
// ·以为char*是字符串类型，定义了一个字符串类型的变量string就可以直接利用了
// ·由于没有对string初始化为0，所以不一定每次运行都出错。

// 空字符串
// ·char buffer[100]="";
// ·这是一个空的字符串，buffer[0] == '\0'
// ·char buffer[]="";
// ·这个数组的长度只有1！

// gets(string)函数
// ·需要头文件#include<string.h>
// ·用于做字符串输入
// ·如果输入长度大于字符串长度-1，读入长度-1个字符

// puts(string)函数
// ·需要头文件#include<string.h>
// ·用于做字符串输出
// ·输出字符串，并换行

// putchar
// ·int putchar(int c);
// ·向标准输出写一个字符
// ·返回写了几个字符，EOF（-1）表示写失败（_end_of_file）是C语言中定义的宏
// ·输入函数的参数不是char类型，而是int类型（但int只能接收一个字符）
// ·返回类型也是一个int，表示这一次写出去了几个字符

// getchar
// ·int getchar(void);
// ·从标准输入读入一个字符
// ·返回类型是int是为了返回EOF(-1)
// 	·Windows  ——》 Ctrl-Z
// 	·Unix  ——》 Ctrl-D

// Ctrl+C	强制程序结束
// Ctrl+Z	getchar返回EOF

// ·程序和显示器之间还有另外一个程序，叫做shell（行编辑工作）（在按下回车之前，程序停留在shell那里）
// （按下回车后，shell中有很大的缓冲区把送进去的填在这里）。
// ·getchar和scanf只是在shell给的缓冲区里读东西。
// ·用户的输入是让shell填这个缓冲区

int main()
{
	const char* str = "Hello";
	printf("'H'=%p\t'e'=%p\n\n", str, str+1);
	printf("*str=%d\t\t*str+1=%d\t*(str+1)=%d\n", *str, *str+1, *(str+1));
	printf("'H'=%d 'e'=%d\n\n\n", 'H', 'e');

	const char* stri = "Du Bist Weltmeister!";

	for (int i = 0; i<strlen(stri); i++) {
		printf("*(stri+%d)=%d\t",  i, *(stri + i));
		if ((i+1) % 5 == 0)printf("\n");
	}

	printf("\n");
	for (int i = 0; i < strlen(stri); i++) {
		printf("'%c'=%d\t\t", stri[i], stri[i]); 
		if ((i+1) % 5 == 0)printf("\n");
	}
	
	return 0;
}