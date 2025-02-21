#include<stdio.h>

// 1.什么是函数？
// ·函数是一块代码，接收零个或多个参数，做一件事情，并返回零个或一个值。
// ·可以先想象成数学中的函数y = f（x）

// void sum（int begin，int end）				//函数头——<返回类型> <函数名> (<参数表>)
// {
// 	int  i；							//函数体——
// 	int  sum  = 0；
	
// 	for （i = begin； i  <=  end;  i++）{
// 		sum  +=  1;
// 	}

// 	printf("%d到%d的和是%d\n",  begin,  end,  sum);
// }

// void类型指函数不含返回值

// 调用函数
// ·函数名（参数值）；
// ·（）起到了表示函数调用的重要作用
// 	·即使没有参数也需要（）
// ·如果有参数，则需要给出正确的数量和顺序
// ·这些值会被按照顺序依次用来初始化函数中的参数

// 2.函数返回
// ·函数有手段知道每一次是哪里调用它，会返回到正确的地方

// ·return停止函数的执行，并送回一个值
// ·return；
// ·return表达式；
// 如果函数有返回值，则必须使用带值的return

// ·一个函数里可以出现多个return语句；（但函数的设计理念是单一出口）

// 多个出口不好做修改与调整

// ·单一return的好处
// 从函数中返回值可以赋值给变量，可以再传递给函数，甚至可以丢弃

// ·没有返回值的函数
// void函数名（参数表）
// ·不能使用带值的return
// 	·可以没有return
// ·调用的时候不能做返回值的赋值

// 3.函数先后关系

// ·把function（）写在上面，是因为：C的编译器自上而下顺序分析代码。
// ·在看到调用函数时，它需要知道函数的样子（函数要用几个参数，每个参数类型如何，返回什么类型），
//  这样它才能检查对函数的调用是否正确。


// 如果不知道，对C语言严格的编译器会编译可能不通过

// 遇到调用函数，编译器会猜测函数类型int f（a，b），如果与之后函数定义不同，
// 则编译不通过

// 为了美观，必须将主函数放在其他函数的前面时，可以将函数头放在主函数前做原型声明，
// 之后做函数定义


// 函数原型，写在主函数前面
// ·函数头，以分号“；”结尾，构成了函数的原型
// ·函数原型的目的是告诉编译器这个函数长什么样子：
// 	·名称
// 	·参数（数量及类型）
// 	·返回类型

// ·实际的函数头再下面，后面跟大括号
// ·原型里可以不写参数名字，但一般仍然写上
// 	编译器检查时不会检查函数的名称，只会检查参数的类型。

// 4.调用函数
// ·如果函数有参数，调用函数时必须传递给它数量、类型正确的值
// ·可以传递给函数的值是表达式的结果，这包括：
// 	·字面量
// 	·变量
// 	·函数返回值
// 	·计算的结果

// 类型不匹配？
// ·调用函数时给的值与参数的类型不匹配是C语言传统上最大的漏洞
// ·编译器总是悄悄地替我们把类型转换好，但这很可能不是我们所期望的
// ·后续的语言，C++/Java在这方面很严格

// C语言在调用函数时，永远只能传值给函数

// 传值
// ·每个函数有自己的变量空间，参数也位于这个独立的空间中，和其他函数没有关系。
// ·过去，对于函数参数表中的参数，叫做“形式参数”，调用函数时给的值。叫做“实际参数”。

// ·由于容易让初学者误会实际参数就是实际在函数中进行计算的参数，
//  误会调用函数的时候把变量而不是值传进去了，所以不建议继续用这种古老的方式来称呼它们。

// ·可以认为，他们是参数和值的关系。

// 5.本地变量

// ·函数的每次运行，就产生了一个独立的变量空间，在这个空间中的变量，
//  是函数这次运行所独有的，称作本地变量
// ·定义在函数内部的变量就是本地变量
// ·参数也是本地变量

// 变量的生存期和作用域
// ·生存期：什么时候这个变量开始出现了，到什么时候它消亡了
// ·作用域：在代码的什么范围内可以访问这个变量（这个变量可以起作用）
// ·对于本地变量，这两个问题是统一的：大括号内 ——》块

// 本地变量的规则
// ·本地变量是定义在块内的
//  ·它可以是定义在函数的块内
//  ·也可以定义在语句的块内
// 	·比如定义在if{}内
// ·程序进入这个块之前，其中的变量不存在，离开这个块，其中的变量就消失了
// ·块外面定义的变量在里面仍然有效
// ·块里面定义了和外面同名的变量则掩盖了外面的。
// （不是所有的语言都这么做的）

// ·不能在一个块内定义同名的变量
// ·本地变量不会被默认初始化
// ·参数在进入函数的时候就被初始化了
// 	·调用函数的时候要给参数一个对应的值，用来初始化参数

// 6.一些有关函数的细节问题

// ——没有参数时
// ·void f(void);
// ·还是
// ·void f();
// ·在传统C中，它表示f函数的参数表未知，并不表示没有参数
// 	声明函数原型时，一定要交代参数类型和个数


// ——逗号运算符？
// ·调用函数时的圆括号里的逗号是标点符号，不是运算符
// ·f（a, b）——》两个参数
// 可以写成
// ·f（(a，b)）——》一个参数

// ——C语言不允许函数嵌套定义


// ——关于main
// ·int main（）也是一个函数
// ·写成int main（void）编译不会出任何问题。
// ·return 0；是有意义的，将0返回给调用它的地方，返回给一小段代码，
//  它会检查返回值，报告给操作系统，这个值对有些程序是有意义的。

int max(int a, int b);
int max3(int a, int b, int c);

int main(void/*parameter*/)
{
	int a, b, c;
	a = 5;
	b = 6;

	c = max(10, 12);
	c = max(a, b);
	c = max(c, 23);
	max(23, 45);		//丢弃返回值

	printf("%d\n", max(a, b));
	printf("c = %d\n", c);

	a = 10;
	b = 11;
	c = 12;
	printf("%d\n", max3(a, b, c));

	return 0;
}

int max(int a, int b)
{
	int ret;

	if (a > b) {
		ret = a;
	}
	else {
		ret = b;
	}

	return ret;		//表达返回值（函数最好是单一出口）
					//将ret的值输出给调用函数的地方
}

int max3(int a, int b, int c)
{
	int d = a > b ? a : b;
	return d > c ? d : c;
}
