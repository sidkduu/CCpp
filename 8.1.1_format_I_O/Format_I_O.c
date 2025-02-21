#include<stdio.h>

int main(int argc, char const* argv[])
{	
	printf("%6d\n", 123);					//右对齐（整个输出6位）
	printf("%-6d\n\n", 123);				//左对齐（共输出6位）
	printf("%+8d\n", 123);					//强制输出+
	printf("%-+8d\n", 123);					//左对齐输出+
	printf("%-+8d\n\n", -123);			//如果是负值就左对齐输出-
	printf("%09d\n", 123);					//右对齐输出（9位）不足用0在左边补齐
	printf("%-09d\n\n\n", 123);			//左对齐输出，左边无法补0

	int len = 9;
	printf("%9.2f\n", 123.0);				//总共占据9个字符的位置，保留小数点后两位，浮点数形式输出
	printf("%*d\n", 9, 123);					//9会被填到*里面去，123是用来满足%d的
	printf("%*d\n\n\n", len, 123);		//可以把数字变成变量，为格式的输出带来了很大的灵活性

	printf("%hhd\n", 12345);				//12345 = 0x3039 --->  0x39=57
	printf("%hd\n\n\n", 12345);

	//int num=0 ;								
	//printf("%d %n\n", 1234,  &num);			//%n统计已经输出多少个字符，填到指针所指的变量去
	//printf("%d\n", num);								//5

	printf("%e\n", 100.0);
	printf("%-7e\n\n\n", 12.0);						//%e不指定输出数据所占的宽度和小数位数，由系统自动指定。按规格化形式输出

	int number=0;
	scanf("%i", &number);							//012
	printf("%d\n", number);							//10
	scanf("%i", &number);							//0x12
	printf("%d\n\n\n", number);					//18

	int k;
	int i1 = scanf("%i", &k);							//读到了一个数
	int i2 = printf("%d\n", k);							//输出读入数的位数和一个换行
	printf("%d:%d\n", i1, i2);

	return 0;
}