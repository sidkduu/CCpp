#include<stdio.h>
#include<cstdint>
#include<time.h>

// inline函数
// ·引入inline函数的主要原因是用它替代C 中复杂易错且不宜维护的宏函数

// 编译器对inline函数的处理步骤一般如下：
// （1）将inline 函数体复制到inline函数调用处
// （2）为所用inline 函数中的局部变量分配内存空间
// （3）将incline 函数的输入参数和返回值映射到调用方法的局部变量空间中
// （4） 如果inline 函数有多个返回点，将其转变为inline 函数代码块末尾的分支

// inline函数非常适合于被经常调用的小函数
// ·在C/C++中，为了解决一些频繁调用的小函数大量消耗栈空间（栈内存）的问题，
//     特别引入inline 修饰符，表示为内联函数。
// ·inline 只适合函数体内代码简单的函数使用，不能包含复杂的结构控制语句如while、switch，
//     并且内联函数不能再内部递归调用

// 在12.2.3中
// inline 在程序内的工作就是在每个for 循环的内部任何调用num_check(i)的地方都换成了 (i % 2 > 0) ? "奇" : "偶";,
// 这样就避免了频繁调用函数对堆栈内存重复开辟所带来的消耗。


// 优缺点
// inline 函数相对宏函数有如下优点：
// （1）内联函数同宏函数一样将在被调用处进行代码展开，
//           省去了参数压栈、栈帧开辟与回收，结果返回等，从而提高程序运行速度。
// （2）内联函数相比宏函数来说，在代码展开时，
//           会做安全检查或自动类型转换（同普通函数），而宏定义则不会。

//  ·使用宏函数时，其书写语法也较为苛刻，如果对宏函数出现如下错误的调用，MAX(a,"Hello")；
//      宏会错误地比较int和字符串，没有参数类型检查，但是使用内联函数的时候，会出现类型不匹配的编译错误。

// （3）在类中声明同时定义的成员函数，自动转化为内联函数，因此内联函数可以访问类的成员变量，宏定义则不能。
// （4）内联函数在运行时可调试，而宏定义不可以。

// 使用inline函数，也要三思慎重。inline函数的缺点总结如下：

// （1）代码膨胀。
// ·inline函数带来的运行效率是典型的以空间换时间的做法。内联是以代码膨胀（复制）为代价，消除函数调用带来的开销。
//     如果执行函数体内代码的时间，相比于函数调用的开销较大，那么效率的收获会很少。
// ·另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。

// （2）inline 函数无法随着函数库升级而升级。
// ·如果f是函数库中的一个inline函数，使用它的用户会将f函数实体编译到他们的程序中。
//     一旦函数库实现者改变f，所有用到f的程序都必须重新编译。
//     如果f是non-inline的，用户程序只需重新连接即可。
//     如果函数库采用的是动态连接，那这一升级的f函数可以不知不觉的被程序使用。

// （3）是否内联，程序员不可控。
// ·inline函数只是对编译器的建议，是否对函数内联，决定权在于编译器。
//     编译器认为调用某函数的开销相对该函数本身的开销而言微不足道或者不足以为之承担代码膨胀的后果则没必要内联该函数。
//     若函数出现递归，有些编译器则不支持将其内联。


// 建议
// （1）使用函数指针调用内联函数将会导致内联失败。
//           也就是说，如果使用函数指针来调用内联函数，那么就需要获取inline函数的地址。
//           如果要取得一个inline函数的地址，编译器就必须为此函数产生一个函数实体，那么就内联失败。

// （2）如果函数体代码过长或者有多重循环语句，if或witch分支语句或递归时，不宜用内联。

// （3）类的 constructors、destructors 和虚函数往往不是 inline 函数的最佳选择。
//           类的构造函数（constructors）可能需要调用父类的构造函数，析构函数同样可能需要调用父类的析构函数，
//           二者背后隐藏着大量的代码，不适合作为inline函数。
//           虚函数（destructors）往往是运行时确定的，而inline是在编译时进行的，所以内联虚函数往往无效。
//           如果直接用类的对象来使用虚函数，那么对有的编译器而言，也可起到优化作用。

// （4）至于内联函数是定义在头文件还是源文件的建议。
//           内联展开是在编译时进行的，只有链接的时候源文件之间才有关系。所以内联要想跨源文件必须把实现写在头文件里。
//           如果一个 inline 函数会在多个源文件中被用到，那么必须把它定义在头文件中。

// 下面比较下内联函数和非内联函数在相同情况下执行时间的情况（Subroutine1 - 12.2.3.1）
// 得出结论：调用函数比调用宏快？？？？
// 宏和运行速度没有关系！  ————胡建伟


// 交换值
inline void inlined_swapf(float p1, float p2)
{
    float tmp = p1;
    p1 = p2;
    p2 = tmp;
}
// float 类型排序
void swapf(float p1, float p2)
{
    float tmp = p1;
    p1 = p2;
    p2 = tmp;
}
// float 类型排序

void selection_sortf1(float a[], int n)
{
    int i, j, mini;
    for (i = 0; i < n - 1; ++i) {
        mini = i;
        for (j = i + 1; j < n; ++j) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        inlined_swapf(*(a + i), *(a + mini));
    }
}
// 交换值
void selection_sortf2(float a[], int n)
{
    int i, j, mini;
    for (i = 0; i < n - 1; ++i) {
        mini = i;
        for (j = i + 1; j < n; ++j) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        swapf(*(a + i), *(a + mini));
    }
}

clock_t _cdecl esp_timer_get_time()
{
    unsigned long long a = clock();
    return a;
}

int main(void)
{
    printf("Start!\n");
    float a[1024] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    volatile uint64_t total_time;
    unsigned long long pre_total_time1=0;
    unsigned long long pre_total_time2 = 0;

    for (double j = 0; j < 10; j++) {
        total_time = esp_timer_get_time();
        for (int i = 0; i < 10000; i++) {
            selection_sortf1(a, sizeof(a) / sizeof(float));
        }
        total_time = esp_timer_get_time() - total_time;
        pre_total_time1 = (pre_total_time1 * j+ total_time) / (j + 1);
    }
    printf("inline: %llu ms\r\n", pre_total_time1);

    for (double j = 0; j < 10; j++) {
        total_time = esp_timer_get_time();
        for (int i = 0; i < 10000; i++) {
            selection_sortf2(a, sizeof(a) / sizeof(float));
        }
        total_time = esp_timer_get_time() - total_time;
        pre_total_time2 = (pre_total_time2 * j + total_time) / (j + 1);
    }
    printf("no-inline: %llu ms\r\n", pre_total_time2);

    return 0;
}