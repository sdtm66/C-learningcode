// 关系运算符重载
// 作用：重载关系运算符，可以让两个自定义类型对象进行对比操作
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person() : age(20), name("sda") {}
    Person(int age1, string name1) : age(age1), name(name1) {}
    bool operator==(Person &p)
    {
        if ((this->age == p.age) && (this->name == p.name))
        {
            return true;
        }
        else
            return false;
    }

private:
    int age;
    string name;
};

void test01()
{
    Person p1(18, "Tom");
    Person p2(18, "Tom");
    if (p1 == p2)
    {
        cout << "两个人相等" << endl;
    }
}

int main(void)
{
    test01();
    return 0;
}