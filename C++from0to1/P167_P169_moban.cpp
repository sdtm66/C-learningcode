//模板：模板就是简历通用的项目，大大提高复用性
//函数模板：C++另一种编程思想称为泛型编程，主要利用的技术就是模板
//C++提供两种模板模板：函数模板和类模板
// 函数模板的作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表
// 语法：  template<typename或者class T>
// 函数声明或定义
// template 声明创建模板  typename 表明其后面的符号是一种数据类型，可以用class代替  T 通用的数据类型，名称可以替换，通常为大写字母
//注意事项：自动类型推导，必须推导出一数的数据类型T，才可以使用；模板必须确定出T的数据类型，才可以使用

#include <iostream>
#include <string>
using namespace std;

void swapint(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swapdouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

//函数模板
template <typename T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    swapint(a, b);
    cout << "a=" << a << ";b=" << b << endl;
    double c = 2.0;
    double d = 3.0;
    swapdouble(c, d);
    cout << "c=" << c << ";d=" << d << endl;
    float e = 4.0;
    float f = 5.0;
    //my_swap(e, f);        //自动类型推导
    my_swap<float>(e, f); //显示指定类型
    cout << "e=" << e << ";f=" << f << endl;
}

void test02()
{
}

int main(void)
{
    test01();
    test02();
    return 0;
}