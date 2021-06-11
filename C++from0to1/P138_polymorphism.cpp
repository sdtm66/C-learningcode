//在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用重写的内容
//因此可以将虚函数改为纯虚函数
//纯虚函数语法：virtual 返回值类型 函数名 (参数列表) = 0；
// 当类中有了纯虚函数，这个类也称为抽象类
//抽象类的特点：无法实例化对象；子类必须重写抽象类中的虚函数，否则也属于抽象类

#include <iostream>
#include <string>
using namespace std;

class Base //抽象类：无法实例化对象；子类必须重写抽象类中的虚函数，否则也属于抽象类
{
public:
    virtual void func() = 0; //纯虚函数
};
class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func函数调用" << endl;
    }
};

void test01()
{
    Base *base = new Son;
    base->func();
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