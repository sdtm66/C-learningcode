#include <iostream>
#include <string>
using namespace std;

//带默认值形参的函数。语法： 返回值类型 函数名（参数=默认值）{}
// 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须要有默认值
//如果函数声明有默认值，函数实现的时候就不能有默认值
int sum(int a = 10, int b = 20, int c = 30);

//函数占位参数。语法： 返回值类型 函数名（数据类型）{}
void func(int a, int)
{
    cout << "该函数有占位参数" << endl;
}

//函数重载：函数名可以相同，提高复用性。满足条件：同一作用域下；函数名相同；函数参数类型不同或者个数不同或者顺序不同； 注意：函数的返回值不可以作为函数重载的条件
void add()
{
    cout << "该函数无意义" << endl;
}
int add(int a, int b)
{
    return a + b;
}
//引用也可以作为函数重载的条件
void ini(int &a)
{
    cout << "ini (int &a)调用" << endl;
}
void ini(const int &a)
{
    cout << "ini (const int &a)调用" << endl;
}
//函数重载碰到默认参数会有二义性
int mul(int a, int b)
{
    return a * b;
}
int mul(int a, int b, int c = 10)
{
    return a * b * c;
}

int main(void)
{
    cout << sum() << endl;
    add();
    int b = add(4, 5);
    cout << b << endl;
    ini(10);   // int &a =10；不合法；const int &a =10；所以会调用void ini (const int &a)
    ini(b);    // int &a =b  合法;因为b可读可写；所以会调用void ini (int &a)；而void ini (const int &a) 限制了 实参为只可读
    mul(1, 1); //出现了二义性
    return 0;
}

//带默认值形参的函数
int sum(int a, int b, int c)
{
    return a + b + c;
}
