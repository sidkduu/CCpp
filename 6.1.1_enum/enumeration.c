#include<stdio.h>
#include<stdlib.h>

enum COLOR {red, yellow, green, blue, apricot, lavender, maple, NumCOLORS/* ��ɫ�������� */};		// ö������

void f(enum COLOR c);

int main(int argc, char const* argv[])
{
	int color = -1;
	const char* colorName = NULL;

	printf("������ϲ������ɫ�Ĵ��룺");
	scanf("%d", &color);

	if (color >= NumCOLORS) {
		printf("��������\n");
		return 0;
	}

	switch (color) {
	case red: colorName = "red"; break;
	case yellow: colorName = "yellow"; break;
	case green: colorName = "green"; break;
	default:colorName = "unkown"; break;
	}

	printf("��ϲ������ɫ��%s\n\n", colorName);

	//
	printf("������ϲ������ɫ�Ĵ��룺");
	enum COLOR t = red;
	scanf("%d", &t);
	printf("&t=%p\n", &t);
	f(t);

	system("pause");
	return 0;
}

void f(enum COLOR c)
{
	printf("&c=%p\n", &c);
	printf("%d\n", c);
}