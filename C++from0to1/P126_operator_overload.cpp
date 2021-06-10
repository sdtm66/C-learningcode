// 函数调用运算符重载
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数
#include <iostream>
#include <string>
using namespace std;

class MyPrint
{
public:
    //重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};

class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

void test01()
{
    MyPrint p1;
    p1("Hello!"); //仿函数
}

void test02()
{
    MyAdd add;
    int res = add(100, 100);
    cout << "res=" << res << endl;
    //匿名函数对象
    cout << MyAdd()(100, 200) << endl;
}

int main(void)
{
    test01();
    test02();
    return 0;
}