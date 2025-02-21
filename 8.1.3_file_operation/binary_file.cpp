#include<stdio.h>
#include"student.h"

void getList(Student aStu[], int number);
int save(Student aStu[], int number);

int main(int argc, char const* argv[])
{
	int number = 0;
	
	printf("输入学生数量：");
	scanf("%d", &number);
	Student aStu[200];

	getList(aStu, number);
	if (save(aStu, number)) {
		printf("保存成功\n");
	}
	else {
		printf("保存失败\n");
	}

	return 0;
}

void getList(Student aStu[], int number)
{
	char format[STR_LEN] = {0};
	sprintf_s(format, "%%%ds", STR_LEN -1);					//sprintf是向一个字符串输出，%%表示输出一个%，%d是输出一个值，s是输出一个字
																						//产生一个格式字符串，存储形如%19s的形式
	
	int i;
	for (i = 0; i < number; i++) {
		printf("第%d个学生:\n", i+1);
		printf("\t姓名:");
		scanf(format, aStu[i].name, 15);
		printf("\t性别:(0-男, 1-女, 2-其他):");
		scanf("%d", &aStu[i].gender);
		printf("\t年龄:");
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