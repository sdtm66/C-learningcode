// 赋值运算符重载
// 默认情况下，c++编译器至少给一个类添加3个函数：1 默认无参构造函数（无参，函数体为空）；2 默认析构函数（无参，函数体为空）；
//3 默认拷贝构造函数，对属性进行值拷贝；4 赋值运算符operator=,对属性进行值拷贝
// 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend void test01();

public:
    Person(int age) : m_Age(new int(age)) {}
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    //重载赋值运算符
    Person &operator=(Person &p)
    {
        //编译器提供的是浅拷贝；
        //m_Age = p.m_Age;
        //应先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age); //深拷贝操作，重新开辟一个堆区内存
        return *this;              //返回对象自身
    }

private:
    int *m_Age;
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;
    cout << *p1.m_Age << endl;
    cout << *p2.m_Age << endl;
    cout << *p3.m_Age << endl;
}

int main(void)
{
    test01();
    return 0;
}
