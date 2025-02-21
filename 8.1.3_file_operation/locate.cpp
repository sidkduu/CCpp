#include<stdio.h>
#include"student.h"

void read(FILE* fp, int index);

int main(int argc, char const* argv[])
{
	FILE* fp;
	errno_t fpp = fopen_s(&fp, "G:\\VS\\VS portfolio\\C_C++\\Curriculum （C）\\13.1.3_二进制文件\\student.data", "r");			//输入student.data - 快捷方式.lnk 会打开快捷方式本体，目前只会打开源文件

	if (fp) {
		fseek(fp, 0L, SEEK_END);
		long size = ftell(fp);											//得到文件的大小
		int number = size / sizeof(Student);					//得到有几个结构
		int index = 0;
		int amount = 0;

		printf("有%d个数据，你要看几个：", number);
		scanf("%d", &amount);
		while (amount--) {
			printf("\n你要看第几个：");
			scanf("%d", &index);	
			read(fp, index - 1);										//index-1
		}
		fclose(fp);
	}

	return 0;
}

void read(FILE* fp, int index)
{
	fseek(fp, index * sizeof(Student), SEEK_SET);		//从头向前走index个结构位置
	Student stu;

	if (fread(&stu, sizeof(Student), 1, fp) == 1) {			//如果读出来一个结构
		printf("第%d个学生：\n", index + 1);
		printf("\t姓名：%s\n", stu.name);
		printf("\t性别：");
		switch (stu.gender) {
		case 0:printf("男\n"); break;
		case 1:printf("女\n"); break;
		case 2:printf("其他\n"); break;
		}
	}
	printf("\t年龄：%d\n", stu.age);
}