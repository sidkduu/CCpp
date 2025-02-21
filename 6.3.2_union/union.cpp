#include<stdio.h>

typedef union {
	int i;
	char ch[sizeof(int)];
} CHI;

int main(int argc, char const* argv[])
{
	CHI chi;
	int i;
	chi.i = 1234;										//1234=0x04D2
	for (i = 0; i < sizeof(int); i++) {
		printf("%02hhX", chi.ch[i]);			//%02hhX，希望输出16进制，宽度为一个字节，结果显示为不足两位时补0
	}	//输出结果：D2040000
	printf("\n");

	return 0;
}

//输出结果与实际结果不同，原因是intel的cpu都是x86处理器,都是小端处理器，原则是低位在前（D2放在04前面）
//ARM处理器是大端机（可以试试在lightly上写查看结果）