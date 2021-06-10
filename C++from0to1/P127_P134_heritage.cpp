// 继承
// 作用：减少重复代码
// 语法： class 子类 : 继承方式 父类
// 子类也称为派生类，父类也成为基类
//继承方式：公共继承；保护继承；私有继承
// 公共继承会继承父类中public和protected里的内容，继承过来的属性也分别是public和protected
// 保护继承会继承父类中public和protected里的内容, 继承过来的属性也全是是protected的
// 私有继承会继承父类中public和protected里的内容, 继承过来的属性也全是是private的
// 父类中所有非静态成员属性都会被子类继承下去
// 父类中私有成员属性 是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
// 子类继承父类后，当创建子类对象，也会调用父类的构造函数；先构造父类，再构造子类，析构的顺序相反
// 继承中，先调用父类的构造函数，再调用子类的构造函数，析构的顺序相反
// 当子类与父类出现同名的成员，访问子类同名成员，直接访问即可，访问父类同名成员，需要加作用域。 语法——   子类对象名.父类名::同名属性
// 如果子类中出现和父类同名的成员函数，子列的同名成员会隐藏掉父类中所有同名成员函数
// 如果想访问到父类中被隐藏的同名成员函数，需要加作用域
// 静态成员和非静态成员出现同名，处理方式一致，只不过有两种访问方式（通过对象和通过类名）
// C++允许一个类继承多个类
//语法：  class 子类：继承方式 父类1，继承方式 父类2
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分。C++实际开发中不建议使用多继承
// 菱形继承（钻石继承），利用虚继承可以解决菱形继承问题  class 子类名: virtual 继承方式 父类名
// 菱形继承带来的主要问题是子列继承两份相同的数据，导致资源浪费以及毫无意义
// 利用虚继承可以解决菱形继承问题
#include <iostream>
#include <string>
using namespace std;

class Basepage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
    };
};

class Java : public Basepage //继承Basepage公共所有内容
{
public:
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};

class Python : public Basepage
{
public:
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};

void test01()
{
    cout << "----------------------" << endl;
    cout << "Java页面如下：" << endl;
    Java ja;
    ja.header();
    ja.content();
    ja.footer();
    cout << "----------------------" << endl;
    cout << "Python页面如下：" << endl;
    Python py;
    py.header();
    py.content();
    py.footer();
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