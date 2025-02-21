#include<stdio.h>
#include"student.h"

void getList(Student aStu[], int number);
int save(Student aStu[], int number);

int main(int argc, char const* argv[])
{
	int number = 0;
	
	printf("����ѧ��������");
	scanf("%d", &number);
	Student aStu[200];

	getList(aStu, number);
	if (save(aStu, number)) {
		printf("����ɹ�\n");
	}
	else {
		printf("����ʧ��\n");
	}

	return 0;
}

void getList(Student aStu[], int number)
{
	char format[STR_LEN] = {0};
	sprintf_s(format, "%%%ds", STR_LEN -1);					//sprintf����һ���ַ��������%%��ʾ���һ��%��%d�����һ��ֵ��s�����һ����
																						//����һ����ʽ�ַ������洢����%19s����ʽ
	
	int i;
	for (i = 0; i < number; i++) {
		printf("��%d��ѧ��:\n", i+1);
		printf("\t����:");
		scanf(format, aStu[i].name, 15);
		printf("\t�Ա�:(0-��, 1-Ů, 2-����):");
		scanf("%d", &aStu[i].gender);
		printf("\t����:");
		scanf("%d", &aStu[i].age);
	}
}

int save(Student aStu[], int number)
{
	int ret = -1;
	FILE* fp;
	errno_t fpp= fopen_s( &fp,"student.data", "w");
	if (fp) {
		ret = fwrite(aStu, sizeof(Student), number, fp);
		fclose(fp);
	}

	return ret == number;
}