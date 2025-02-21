#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// C语言提供了很多函数帮助我们处理字符串

// string.h
// ·strlen		·strcmp
// ·strcpy	·strcat
// ·strchr		·strstr

// 1.strlen
// ·size_t  strlen(const char* s);
// ·返回s字符串长度（不包括结尾的0）

// strnlen
// ·size_t strnlen(const char* s, size_t maxlen);
// ·说明：获取字符串s中的字符个数n，不包括结尾的'\0';
// ·如果n <= maxlen, 则返回n, 否则返回maxlen。

// 2.strcmp							//compare
// ·int strcmp(const char* s1, const char* s2);		//两个字符串都是常量，比较的过程中不能修改
// ·比较字符串，返回：
// ·0：s1 == s2
// ·1:   s1  >  s2
// ·-1:  s1  <  s2


// strcmp（）会根据ASCII码依次比较str1 和 str2 的每一个字符，直到出现不到的字符，或者到达字符串的末尾（遇见\0）
// strcmp()		对两个字符串进行大小写敏感的比较
// strcmpi()		对两个字符串进行大小写不敏感的比较
// stricmp()		同strcmpi()
// strncmp()		对两个字符串的一部分进行大小写敏感的比较
// strnicmp()		对两个字符串的一部分进行大小写不敏感的比较

// 3.strcpy

// ·char* strcpy(char* restrict dst, const char*restrict src);	//第一个参数是目的，第二个参数是源
// ·把src的字符串拷贝到dst
// ·restrict表明src和dst不重叠(C99)
// ·返回dst
// ·为了能链起代码来

// 复制一个字符串
// char* dst  =  (char*)malloc(strlen(src)+1);
// cahr* dst  =  (char*)malloc((unsigned long)sizeof(src));	//不确定能否这么写
// strcpy(dst, src);

// ·可以搜一下strcpy_s（C++）


// 4.strcat（catenate）
// ·char* strcat(char* restrict s1, const char* restrict s2);
// ·把s2拷贝到s1的后面，接成一个长的字符串
// ·返回s1
// ·s1必须有足够的空间

// 安全问题
// ·strcpy和strcat都可能出现安全问题
// ·如果目的地没有足够空间？

// 使用安全版本
// ·char* strncpy(char* restrict dst, const char* restrict src, size_t n);		//拷过去多少个字符
// ·char* strncat(char* restrict s1, const char* restrict s2, size_t n);			//连上多少个字符
// ·int strncmp(const char* s1, const char* s2, size_t n);				//比较字符串前几位


// 5. strstr
// 字符串中找字符
// ·char* strchr(const char* s, int c);
// ·char* strrchr(const char* s, int c);
// ·返回null表示没有找到
// ·返回非null表示找到了并返回给一个指向那个字符的指针

// 如何寻找第二个？

// 字符串中寻找字符串
// ·char* strstr(const char* s1, const char* s2);			//字符串中寻找一个字符串
// ·char* strcasestr(const char* s1, const char* s2);		//寻找字符串的过程中忽略大小写


int stringlength(const char* s);
int string_length(const char* s);
int mycmp(const char* s1, const char* s2);
int mycmpare(const char* s1, const char* s2);
char* mycpy(char* dst, const char* src);
char* mycopy(char* dst, const char* src);
char* mystrcat(char* dst, const char* src);
char* mystrcatenate(char* dst, const char* src);

int main(int argc, char const* srgv[])
{
	// strlen
	char line[] = "Hello";
	printf("strlen = %lu\n", (unsigned long)strlen(line));
	printf("strlen = %lu\n", (unsigned long)stringlength(line));
	printf("strlen = %lu\n", (unsigned long)string_length(line));
	printf("sizeof = %zu\n", sizeof(line));

	// strcmp
	char s1[] = "abc";
	char s2[] = "abc";

	printf("(s1 == s2)= %d\n", s1 == s2);					//数组的比较永远是false，判断“==”表达的是两个数组是否是相同的地址
	printf("(s1, s2) = %d\n", strcmp(s1, s2));

	if (strcmp(s1, s2) == 0);										//如果两数组相同，strcmp返回值永远为0，直接写的话 if 不会进行下去
	
	char s3[] = "abc";
	char s4[] = "bbc";
	char s5[] = "Abc";
	char s6[] = "abc ";
	
	printf("(s3, s4) = %d\n", strcmp(s3, s4));			//s3比s4小
	printf("(s3, s5) = %d\n", strcmp(s3, s5));			//s3比s5大
	printf("(s3, s6) = %d\n", strcmp(s3, s6));			//s3比s6小
	printf("i(s3, s5)= %d\n", _stricmp(s3, s5));			//大小写不敏感的情况下，s3和s5相同

	// strcpy
	char s1[5] = "abc", s3[5] = "abc", s5[6] = "abc";
	const char* s2 = "abfe", * s4 = "abfe", * s6 = "abfe";
	strncpy(s1, s2, 3);
	mycpy(s3, s4);
	mycopy(s5, s6);
	printf("%s\n%s\n%s\n", s1, s3, s5);

	// strcat
	char s1[12] = "HELLO", s3[12] = "HELLO", s5[12] = "HELLO";
	char s2[] = "world!", s4[] = "world!", s6[] = "world!";
	strncat(s1, s2, 11);			
	mystrcat(s3, s4);
	mystrcatenate(s5, s6);
	printf("%s\n%s\n%s\n", s1, s3, s5);

	// strstr
	//从一个字符串中寻找一个字符
	char s[] = "hello";
	char* p = strchr(s, 'l');
	printf("%s\n", p );
	
	//寻找第二个字符
	p = strchr(p+1/*++p*/, 'l');
	printf("%s\n", p);

	//找到特定字符，将在其后面的部分复制到另一个字符串上
	char* p1 = strchr(s, 'l');
	char* t = (char*)malloc(strlen(p1) + 1);
	strcpy(t, p1);
	printf("%s\n", t);
	free(t);

	//找到特定字符，将在其前面的部分复制到另一个字符串上
	char c = *p1;
	*p1 = '\0';
	char* t1 = (char*)malloc(strlen(s) + 1);
	strcpy(t1, s);
	printf("%s\n", t1);
	free(t1);
	*p1 = c;
	printf("%s\n", s);
	

	return 0;
}

int stringlength(const char* s)
{
	int idx = 0;
	while (s[idx] != '\0') idx++;

	return idx;
}

int string_length(const char* s)
{
	int idx = 0;
	while (s[idx]) idx++;

	return idx;
}

int mycmp(const char* s1, const char* s2)
{
	int idx = 0;
	while (s1[idx] == s2[idx] && s1[idx] != '\0') idx++;
	
	return s1[idx] - s2[idx];
}

int mycmpare(const char* s1, const char* s2)					//直接使用指针判断
{
	while (*s1 == *s2 && *s1 != '\0') {				
		s1++;									//s1指向下一个
		s2++;									//s2指向下一个
	 }												//一直到指向某个不相等的或者指到了相等但为'\0'后结束
	return *s1 - *s2;
}

char* mycpy(char* dst, const char* src)
{
	int idx = 0;
	while (src[idx] != '\0') {
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';

	return dst;
}

char* mycopy(char* dst, const char* src) {
	char* ret = dst;						//用ret记录初始位置，dst在进行复制操作移动指针已经到该字符串的尾部了
													//如果返回dst，当前dst指向字符尾部，再去调用遍历显示会越界，或者调用乱七八糟的值
														//当然，如果循环完成之后再加上*dst = *ret返回dst也是没问题的

	while (*dst++ = *src++);			//while(*src) *dst++ = *src++;
																	//while循环体内赋值运算的结果是*src，于是可以将循环体变为循环条件，优化成一个空循环
	*dst = '\0';									
	return ret;
}

char* mystrcat(char* dst, const char* src)
{
	int idx = 0; 
	while (src[idx++])dst[strlen(dst)] = src[idx-1];
	dst[strlen(dst)] = '\0';
	return dst;
}

char* mystrcatenate(char* dst, const char* src)
{
	while (dst[strlen(dst)] = *src++);
	dst[strlen(dst)] = '\0';
	return dst;
}