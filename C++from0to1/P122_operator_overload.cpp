// 左移运算符重载
// 作用：可以输出自定义的数据类型
// 只能利用全局函数重载运算符
// 重载左移运算符配合友元可以实现输出自定义数据类型；
#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend ostream &operator<<(ostream &cout, Person p);

public:
    Person(int a, int b) : m_A(a), m_B(b) {}

private:
    int m_A;
    int m_B;
};

//左移运算符<<重载
ostream &operator<<(ostream &cout, Person p) //本质operator<<(cout,p)； 简化 cout << p;
{
    cout << "m_A=" << p.m_A << ";m_B=" << p.m_B << endl;
    return cout; //链式编程思想
}

int main(void)
{
    Person p(10, 20);
    cout << p << endl;
    return 0;
}