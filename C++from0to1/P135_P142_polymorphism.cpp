// 多态
//（1）静态多态：函数重载和运算符重载属于静态多态，复用函数名
//（2）动态多态：派生类和虚函数实现运行时多态
//静态多态与动态多态的区别：
//（1）静态多态的函数地址早绑定  编译阶段确定函数地址
//（2）动态多态的函数地址晚绑定  运行阶段确定函数地址
// 动态多态满足条件：1 有继承关系；2 子类要重写父类的虚函数
// 动态多态的使用：父类的指针或者引用指向子类对象
#include <iostream>
#include <string>
using namespace std;
//动物类
class Animal
{
public:
    //虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};
//猫类
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};
//执行说话的函数
//地址早绑定，在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定，virtual void speak()
void dospeak(Animal &animal)
{
    animal.speak();
}

void test01()
{
    Cat cat;
    dospeak(cat);
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