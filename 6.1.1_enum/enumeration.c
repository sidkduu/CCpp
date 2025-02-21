#include<stdio.h>
#include<stdlib.h>

enum COLOR {red, yellow, green, blue, apricot, lavender, maple, NumCOLORS/* 颜色的总数量 */};		// 枚举类型

void f(enum COLOR c);

int main(int argc, char const* argv[])
{
	int color = -1;
	const char* colorName = NULL;

	printf("输入你喜欢的颜色的代码：");
	scanf("%d", &color);

	if (color >= NumCOLORS) {
		printf("输入有误\n");
		return 0;
	}

	switch (color) {
	case red: colorName = "red"; break;
	case yellow: colorName = "yellow"; break;
	case green: colorName = "green"; break;
	default:colorName = "unkown"; break;
	}

	printf("你喜欢的颜色是%s\n\n", colorName);

	//
	printf("输入你喜欢的颜色的代码：");
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