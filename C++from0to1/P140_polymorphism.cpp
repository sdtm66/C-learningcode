// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 解决方式：将父类中的析构函数改为虚析构或者纯虚析构
// 虚析构和纯虚析构共性：可以解决父类指针释放子类对象；都需要有具体的函数实现
// 虚析构和纯虚析构区别：如果是纯虚析构，该类属于抽象类，无法实例化对象
// 虚析构语法： virtual ~类名(){}
// 纯虚构语法： virtual ~类名()=0；
//             类名::~类名(){}
//
//
//

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }
    virtual ~Animal() //虚析构函数调用：解决父类指针释放子类对象时不干净的问题
    {
        cout << "Animal析构函数调用" << endl;
    }
    //virtual ~Animal()=0; //纯虚析构函数,需要声明也需要实现
    virtual void speak() = 0;
};
// Animal::~Animal() //纯虚析构函数实现
// {
//     cout << "Animal析构函数调用" << endl;
// }

class Cat : public Animal
{
public:
    Cat(string name) : Name(new string(name))
    {
        cout << "Cat构造函数调用" << endl;
    }
    ~Cat()
    {
        if (Name != NULL)
        {
            cout << "Cat析构函数调用" << endl;
            delete Name;
            Name = NULL;
        }
    }
    virtual void speak()
    {
        cout << *Name << "小猫在说话" << endl;
    }

    string *Name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    delete animal; //父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
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