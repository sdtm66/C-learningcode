//运算符重载的概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 作用：实现两个自定义数据类型的运算
// 对于内置的数据类型，编译器知道如何进行计算
//
//
//

#include <iostream>
#include <string>
using namespace std;

//加号运算符重载
// 1 成员函数重载+号
// 2 全局函数重载+号

class Person
{
public:
    Person() : m_A(10), m_B(10){};
    Person(int A, int B) : m_A(A), m_B(B){};

public:
    int m_A;
    int m_B;

public:
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
};

int main(void)
{
    Person p1;
    Person p2;
    Person p = p1 + p2;
    cout << p.m_A << ";" << p.m_B << endl;

    return 0;
}