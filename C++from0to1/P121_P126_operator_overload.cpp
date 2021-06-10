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
    //成员函数实现重载+号
    Person operator+(Person &p) //加号运算符重载：赋予运算符新的定义，对自定义数据类型进行运算操作
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    //运算符重载也可以发生函数重载
    Person operator+(int a) //加号运算符重载：赋予运算符新的定义，对自定义数据类型进行运算操作
    {
        Person temp;
        temp.m_A = this->m_A + a;
        temp.m_B = this->m_B + a;
        return temp;
    }
};

//全局函数实现重载+号
// Person operator+(Person &p1, Person &p2)
// {
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp;
// }

int main(void)
{
    Person p1;
    Person p2;
    Person p = p1 + p2; // Person +Person
    //Person p = p1.operator+(p2); //成员函数实现重载+号本质调用
    //Person p = operator+(p1,p2)//全局函数实现重载+号本质调用
    cout << p.m_A << ";" << p.m_B << endl;
    //运算符重载也可以发生函数重载
    Person p3 = p1 + 100; //Person+int
    cout << p3.m_A << ";" << p3.m_B << endl;
    return 0;
}