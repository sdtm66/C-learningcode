//类模板：建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表
// template <typename T>
//类模板没有自动类型推导的使用方式
//类模板在模板参数列表中可以有默认参数
//普通类中的成员函数一开始就可以创建；类模板中的成员函数在调用时才创建
// 类模板对象做函数参数：1 指定传入类型；2 参数模板化；3 整个类模板化
//当类模板碰到继承时，子类的注意事项：
//当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中的类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定出父类中T的类型，子类也需变成类模板

#include <iostream>
#include <string>
using namespace std;

template <typename NameType = string, typename AgeType = int> //类模板在模板参数列表中可以有默认参数，这里默认参数NameType = string，AgeType = int
class Person
{
public:
    Person(NameType name1, AgeType age1) : name(name1), age(age1) {}
    NameType name;
    AgeType age;
    void showPerson();
};
// 类模板的成员函数的类外实现
template <typename NameType, typename AgeType> //不能在类外部的类模板成员函数上指定默认模板参数
void Person<NameType, AgeType>::showPerson()
{
    cout << "name:" << name << "; age:" << age << endl;
}

// 类模板对象做函数参数：1 指定传入类型：Person<string, int> ；使用得最多
void printPerson1(Person<string, int> &p)
{
    cout << "类模板对象做函数参数：1 指定传入类型" << endl;
    p.showPerson();
}
// 类模板对象做函数参数：2 参数模板化
template <typename NameType = string, typename AgeType = int>
void printPerson2(Person<NameType, AgeType> &p)
{
    cout << "类模板对象做函数参数：2 参数模板化" << endl;
    cout << "NameType的数据类型：" << typeid(NameType).name() << endl;
    cout << "AgeType的数据类型：" << typeid(AgeType).name() << endl;
    p.showPerson();
}
// 类模板对象做函数参数：3 整个类模板化
template <typename T>
void printPerson3(T &p)
{
    cout << "类模板对象做函数参数：3 整个类模板化" << endl;
    cout << "T的数据类型：" << typeid(T).name() << endl;
    p.showPerson();
}

//类模板与继承
template <typename NameType = string, typename AgeType = int>
class Father
{
public:
    NameType name;
    AgeType age;
    void showPerson()
    {
        cout << "name:" << name << "; age:" << age << endl;
    }
};
class Son1 : public Father<string, int> //当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中的类型
{
};
template <typename T1, typename T2>
class Son2 : public Father<T1, T2> //如果想灵活指定出父类中T的类型，子类也需变成类模板
{
};

void test01()
{
    //Person p1("张三", 24); //错误语法，类模板没有自动类型推导的使用方式
    Person<string, int> p1("张三", 24);
    p1.showPerson();
    Person<> p2("李思", 23); //
    p2.showPerson();
    printPerson1(p2);
    printPerson2(p2);
    printPerson3(p2);

    Son1 p3;
    p3.name = "王五";
    p3.age = 34;
    p3.showPerson();
    Son2<string, int> p4;
    p4.name = "潘六";
    p4.age = 54;
    p4.showPerson();
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