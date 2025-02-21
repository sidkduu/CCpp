#include<stdio.h>
#include"student.h"

void read(FILE* fp, int index);

int main(int argc, char const* argv[])
{
	FILE* fp;
	errno_t fpp = fopen_s(&fp, "G:\\VS\\VS portfolio\\C_C++\\Curriculum ��C��\\13.1.3_�������ļ�\\student.data", "r");			//����student.data - ��ݷ�ʽ.lnk ��򿪿�ݷ�ʽ���壬Ŀǰֻ���Դ�ļ�

	if (fp) {
		fseek(fp, 0L, SEEK_END);
		long size = ftell(fp);											//�õ��ļ��Ĵ�С
		int number = size / sizeof(Student);					//�õ��м����ṹ
		int index = 0;
		int amount = 0;

		printf("��%d�����ݣ���Ҫ��������", number);
		scanf("%d", &amount);
		while (amount--) {
			printf("\n��Ҫ���ڼ�����");
			scanf("%d", &index);	
			read(fp, index - 1);										//index-1
		}
		fclose(fp);
	}

	return 0;
}

void read(FILE* fp, int index)
{
	fseek(fp, index * sizeof(Student), SEEK_SET);		//��ͷ��ǰ��index���ṹλ��
	Student stu;

	if (fread(&stu, sizeof(Student), 1, fp) == 1) {			//���������һ���ṹ
		printf("��%d��ѧ����\n", index + 1);
		printf("\t������%s\n", stu.name);
		printf("\t�Ա�");
		switch (stu.gender) {
		case 0:printf("��\n"); break;
		case 1:printf("Ů\n"); break;
		case 2:printf("����\n"); break;
		}
	}
	printf("\t���䣺%d\n", stu.age);
}