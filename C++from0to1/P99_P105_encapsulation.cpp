// c++面向对象的三大特性：封装，继承与多态
// 封装的意义1：将属性与行为作为一个整体，设计类
// 封装的意义2：类装载设计时，可以把属性和行为放在不同的权限下，加以控制。
// 访问的权限有三种：
// （1）public 公共权限 类外可以访问；
// （2）protected 保护权限 类内可以访问 类外不可访问 子类可以继承
// （3）private 私有权限 类内可以访问 类外不可访问 子类不可继承
// 语法：  class 类名（访问权限：属性/行为）
//类中的属性和行为，我们统一称为成员
//属性 成员属性 成员变量
//行为 成员函数 成员方法
// 在c++中struct和class的唯一区别在于默认的访问权限不同：struct默认权限为公共，class默认权限为私有
// 将所有成员属性设置为私有，可以自己控制读写权限
// 对于写权限，我们可以检测数据的有效性
#include <iostream>
#include <string>
#define PI 3.1415926
using namespace std;

//设计一个圆类，求圆的周长
class Circle
{
public:
    double radius;
    double calculate_perimeter()
    {
        return 2 * PI * radius;
    }
};

class Person
{
public:
    string name;

public:
    void init()
    {
        name = "张三";
        car = "宝马";
        wife = "李四";
    }

protected:
    string car;

private:
    string wife;
};

int main(void)
{
    Circle c1; //实例化一个对象
    cout << "请输入圆的半径：" << endl;
    cin >> c1.radius;
    cout << "圆的周长为：" << c1.calculate_perimeter() << endl;

    Person p1;
    p1.init();
    cout << p1.name << endl;

    return 0;
}