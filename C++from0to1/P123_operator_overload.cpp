// 递增运算符重载
// 前置递增返回引用，后置递增返回值

#include <iostream>
#include <string>
using namespace std;

class MyInteger
{
    friend ostream &operator<<(ostream &cout, MyInteger p);

public:
    MyInteger() : m_Num(0){};
    //重载前置++运算符
    MyInteger &operator++() //返回引用是为了一直对一个数据进行操作；
    {
        m_Num++;      //先进行++运算
        return *this; //再将自身返回
    }
    //重载后置++运算符
    MyInteger operator++(int)
    //返回值是因为temp地址在函数调用完就会被销毁；int 代表占位参数，可以用于区分前置和后置递增；operator++()代表前置递增重载；operator++(int)代表后置递增重载
    {
        MyInteger temp = *this; //先记录当时结果
        m_Num++;                //再进行++运算
        return temp;            //再将自身返回
    }

private:
    int m_Num;
};
ostream &operator<<(ostream &cout, MyInteger p) //本质operator<<(cout,p)； 简化 cout << p;
{
    cout << p.m_Num << endl;
    return cout; //链式编程思想
}

int main(void)
{
    //重载前置++运算符
    MyInteger i;
    cout << ++(++i) << endl;
    //重载后置++运算符
    MyInteger j;
    cout << j++ << endl;
    cout << j << endl;
    return 0;
}