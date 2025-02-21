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
		printf("%02hhX", chi.ch[i]);			//%02hhX��ϣ�����16���ƣ����Ϊһ���ֽڣ������ʾΪ������λʱ��0
	}	//��������D2040000
	printf("\n");

	return 0;
}

//��������ʵ�ʽ����ͬ��ԭ����intel��cpu����x86������,����С�˴�������ԭ���ǵ�λ��ǰ��D2����04ǰ�棩
//ARM�������Ǵ�˻�������������lightly��д�鿴�����