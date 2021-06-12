//普通函数与函数模板的区别
// 普通函数调用时可以发生自动类型转换（隐式类型转换）
// 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
// 如果利用显示指定类型的方式，可以发生隐式类型转换
// 总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T
// 调用规则如下：
// 1 如果函数模板和普通函数都可以实现，优先调用普通函数
// 2 可以通过空模板参数列表来强制调用函数模板
// 3 函数模板也可以重载
// 4 如果函数模板可以产生更好的匹配，优先调用函数模板
// 总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性；
// 局限性：自定义数据类型
//利用具体化的模板，可以解决自定义类型的通用化
// 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
#include <iostream>
#include <string>
using namespace std;

int my_add(int a, int b)
{
    cout << "调用第一个函数" << endl;
    return a + b;
}

template <typename T>
T my_add(T a, T b)
{
    cout << "调用第二个函数" << endl;
    return a + b;
}

template <typename T>
T my_add(T a, T b, T c)
{
    cout << "调用第三个函数" << endl;
    return a + b + c;
}
//自定义数据类型利用函数模板比较
class Person
{
public:
    Person(string name1, int age1) : name(name1), age(age1) {}

public:
    string name;
    int age;
};
//利用具体化Person的版本实现代码，具体化优先调用
template <class T>
bool my_compare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return true;
    }
}

template <>
bool my_compare(Person &p1, Person &p2)
{
    if ((p1.name == p2.name) && (p2.age == p2.age))
    {
        return true;
    }
    else
    {
        return false;
    }
};

void test01()
{
    int a = 10;
    char b = 'b';
    char c = 'c';
    cout << my_add(a, b) << endl; //如果函数模板和普通函数都可以实现，优先调用普通函数；发生隐式类型转换，char转换成int
    //cout << my_add2(a, b) << endl; //自动类型推导，不会发生隐式类型转换
    cout << my_add<int>(a, b) << endl;     //显示指定类型，发生隐式类型转换，char转换成int
    cout << my_add<>(a, 20) << endl;       //可以通过空模板参数列表来强制调用函数模板
    cout << my_add<int>(a, b, 20) << endl; //函数模板也可以重载
    cout << my_add(b, c) << endl;          // 如果函数模板可以产生更好的匹配，优先调用函数模板
}

void test02()
{
    Person p1("Tom", 23);
    Person p2("Tom", 23);
    bool res = my_compare(p1, p2);
    if (res)
    {
        cout << "p1==p2" << endl;
    }
    else
    {
        cout << "p1!=p2" << endl;
    }
}

int main(void)
{
    test01();
    test02();
    return 0;
}